/*

    This file is part of GeoGen.

    GeoGen is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    GeoGen is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with GeoGen.  If not, see <http://www.gnu.org/licenses/>.

*/

// system and SDL headers
#include <stdio.h>   
#include <stdlib.h> 
#include <string>
//#include <SDL/SDL.h> 
#include <math.h>
#include <time.h> 
#include <iostream>
#include <fstream>
#include <sstream>
#include <assert.h>
#include <time.h>

using namespace std;

#ifdef NO_GGEN_LIB
	#include "ggen.h"
	#include "ggen_squirrel.h"
#else
	#pragma comment(lib,"../lib/GeoGen.lib")
	#include "../include/geogen.h"
#endif

#include "EasyBMP.h"
#include "../external/ArgDesc/ArgDesc.cpp"

struct GGen_Params{
	string input_file;
	string output_file;
	string output_directory;
	
	int random_seed;
	
	bool all_random;
	bool no_rescaling;
	bool ignore_zero;
	bool help;
	bool syntax_check_mode;
	bool param_list_mode;
	bool stupid_mode;
	bool manual_mode;
	bool disable_secondary_maps;
	
	vector<std::string> script_args;
	
	GGen_Params()
		:input_file(""),
		output_file("out.bmp"),
		output_directory("../temp/"),
		random_seed(-1),
		all_random(false),
		no_rescaling(false),
		ignore_zero(false),
		help(false),
		syntax_check_mode(false),
		param_list_mode(false),
		stupid_mode(false),
		manual_mode(false),
		disable_secondary_maps(false)
	{}
};

GGen_Params _params;

bool SaveAsBMP(const int16* data, unsigned int width, unsigned int height, const char* implicit_path, const char* name = NULL){
	stringstream path_out;

	if(name == NULL){
		path_out << implicit_path;
		cout << "Saving main bitmap...\n" << flush;
	}
	else if(_params.disable_secondary_maps){
		return false;
	}
	else{
		path_out << _params.output_directory << name << ".bmp";
		cout << "Saving map \"" << name << "\"...\n" << flush;
	}
	
	//
	
	int format_max_value = 255;
	int format_min_value = 0;
	
	// is scaling wanted?
	if(_params.no_rescaling == false){
		int16* new_data = new int16[width * height];
		
		// calculate the extremes
		int32 max = - 2 << 14;
		int32 min = 2  << 14;
		for(uint32 i = 0; i < width * height; i++){
			if(data[i] > max) max = data[i];
			if(data[i] < min) min = data[i];
		}

		// if max == min, then whole map is black, scaling would be useless
		if(max - min > 0){
			if(_params.ignore_zero) max = max - min;
			else if(!format_min_value == 0){
				cout << "SYMMETRIC SCALING IS NOT IMPLEMENTED YET!";
				return false;
			}

			if(max > 0){
				for(uint32 i = 0; i < width * height; i++){
					if(_params.ignore_zero) new_data[i] = (data[i] - min) * format_max_value / max;
					else if(data[i] > 0) new_data[i] = data[i] * format_max_value / max;
					else new_data[i] = 0;
				}
			}
			
			data = new_data;
		}
	}

	BMP output;

	output.SetBitDepth(32);

	output.SetSize(width, height);

	for(unsigned int i = 0; i < height; i++){
		for(unsigned int j = 0; j < width; j++){
			output(j,i)->Red = output(j,i)->Green = output(j,i)->Blue = (ebmpBYTE) data[j + width * i];
		}		
	}

	output.WriteToFile(path_out.str().c_str());

	if(name != NULL) cout << "Executing...\n" << flush;

	return true;
}


template <class T>
T random(T min, T max){
	double random = (double)rand() / (double) RAND_MAX;
	T output = min + (T) (random * (double)(max - min));
	return output;
}

void ReturnHandler(char* name, const int16* map, int width, int height){
	SaveAsBMP(map, width, height, "", name); 
}

void ProgressHandler(int current_progress, int max_progress){
	cout << (int) (( (double) current_progress / (double) max_progress) * 100) <<  "% Done...\n" << flush;
}

int main(int argc,char * argv[]){
	//char* buf = new char[2000];

	cout << "Initializing...\n" << flush;

	// initialize argument support
	ArgDesc args(argc, argv);
	args.SetPosArgsVector(_params.script_args);
	
	args.AddStringArg('i', "input", &_params.input_file); 
	args.AddStringArg('o', "output", &_params.output_file);
	args.AddStringArg('d', "output-directory", &_params.output_directory);
	
	args.AddIntArg('s', "seed", &_params.random_seed);
	
	args.AddBoolArg('a', "all-random", &_params.all_random);
	args.AddBoolArg('n', "no-rescaling", &_params.no_rescaling);
	args.AddBoolArg('z', "ignore-zero", &_params.ignore_zero);
	args.AddBoolArg('h', "help", &_params.help);
	args.AddBoolArg('x', "syntax-check", &_params.help);
	args.AddBoolArg('p', "param-list", &_params.param_list_mode);
	args.AddBoolArg('e', "simple", &_params.stupid_mode);
	args.AddBoolArg('m', "manual", &_params.manual_mode);
	args.AddBoolArg('D', "disable-secondary-maps", &_params.disable_secondary_maps);
	
	// read the arguments
	args.Scan();

	// no arguments->perhaps the executable was launched directly from window manager->engage stupid mode
	if(argc == 1){
		_params.stupid_mode = true;
	}

	// no input file -> ask the user
	if(_params.input_file == ""){
		cout << "Please enter path to a script file: ";
		cin >> _params.input_file;
	}

	// let the window manager user know where the output goes
	if(_params.stupid_mode){
		cout << "Output will be saved as ./out.bmp\n";
	}

	// load the script from file
	ifstream in_stream;
	in_stream.open(_params.input_file.c_str());

	if(!in_stream.is_open()){
		cout << "Could not open the script file!\n" << flush;
		if(_params.stupid_mode) system("pause");
		return -1;
	}

	// read the file line by line
	string str,strTotal;
	getline(in_stream,str);
	while ( in_stream ) {
	   strTotal += "\n" + str;
	   getline(in_stream,str);
	}

	in_stream.close();

	// create the primary GeoGen object (use Squirrel script interface)
	GGen_Squirrel* ggen = new GGen_Squirrel();

	cout << "Compiling...\n" << flush;

	ggen->SetReturnCallback(ReturnHandler);
	ggen->SetProgressCallback(ProgressHandler);

	// pump the script into the engine and compile it
	if(!ggen->SetScript(strTotal.c_str())){
		cout << "Compilation failed!\n" << flush;
		delete ggen;
		if(_params.stupid_mode) system("pause");
		return -1;
	}
	else if(_params.syntax_check_mode){
		cout << "OKAY\n" << flush;
		
		delete ggen;
		return 0;
	}

	cout << "Loading map info...\n" << flush;

	// fetch the list of arguments from the script file
	ggen->LoadArgs();

	// make sure the random seed is prepared
	if(_params.random_seed == -1){
		// no seed was entered -> random random seed
		_params.random_seed = (int) time(0);
	}

	// let the std c++ generator use our seed
	srand(_params.random_seed);

	// param list mode
	if(_params.param_list_mode){
		cout << "PARAMS\n" << flush;
		for(uint8 i = 0; i < ggen->num_args; i++){
			GGen_ScriptArg* a = ggen->args[i];
			
			char type = 'N';
			
			switch(a->type){
				case GGEN_BOOL : type = 'B'; break;
				case GGEN_INT : type = 'I'; break;
				case GGEN_ENUM : type = 'E'; break;
			}
			
			cout << a->label << ";" <<  a->description << ";" << type << ";" << ";" << a->min_value << ";" << a->max_value << ";" << a->step_size << ";" << a->num_options << ";";
		
			if(a->type == GGEN_ENUM){
				for(int j = 0; j < a->num_options; j++){
					if(j > 0) cout << ",";
					cout << a->options[j];
					
				}
				
			}
			
			cout << "\n" << flush;
		}
		
		cout << "END\n" << flush;
				
		delete ggen;
		return 0;
	}
	// manual/stupid mode
	else if(_params.manual_mode || _params.stupid_mode){
		cout << "	Please set map parameters:\n";
		
		// loop through all the map arguments 
		for(uint8 i = 0; i < ggen->num_args; i++){
			GGen_ScriptArg* a = ggen->args[i];

			char* buf = new char[16];

			cout << "	" << ggen->args[i]->label << " (";
			
			if(ggen->args[i]->type == GGEN_INT) cout << "integer in range " << ggen->args[i]->min_value << "-" << ggen->args[i]->max_value << "): ";
			else if(ggen->args[i]->type == GGEN_BOOL) cout << "0 = No, 1 = Yes): ";
			else if(ggen->args[i]->type == GGEN_ENUM) {
				for(int j = 0; j < ggen->args[i]->num_options; j++){
					if(j > 0) cout << ", ";
					cout << j << " = " << ggen->args[i]->options[j];
				}
				cout << "): ";
			}
			
			cin >> buf;

			// use default (or random if in allrandom mode) value if fist char of the input is not number
			if(buf[0] >= '0' && buf[0] <= '9') {
				if(_params.all_random) ggen->args[i]->SetValue(random(ggen->args[i]->min_value, ggen->args[i]->max_value));
				else ggen->args[i]->SetValue(atoi(buf));
			}
			
			delete buf;
		}		
	}
	// auto mode
	else{
		// loop through all the map arguments 
		for(uint8 i = 0; i < ggen->num_args; i++){

			if(i < _params.script_args.size() && _params.script_args[i] != "r" && _params.script_args[i] != "d"){
				ggen->args[i]->SetValue(atoi(_params.script_args[i].c_str()));
			}

			// should the value be generated randomly?
			else if(_params.all_random || (i < _params.script_args.size() && _params.script_args[i] == "r")){
				ggen->args[i]->SetValue(random(ggen->args[i]->min_value, ggen->args[i]->max_value));
			}
		}
	}

	cout << "Executing with seed " << _params.random_seed << "...\n" << flush;

	// execute the main part of the script
	int16* data = ggen->Generate();

	if(data == NULL){
		cout << "Map generation failed!\n" << flush;
		delete ggen;
		if(_params.stupid_mode) system("pause");
		return -1;		
	}
	
	assert(data != NULL);

	// flush the bitmap
	SaveAsBMP(data, ggen->output_width, ggen->output_height, _params.output_file.c_str());

	cout << "Cleanup...\n" << flush;

	delete ggen;

	cout << "Done!\n" << flush;

	if(_params.stupid_mode) system("pause");

	return 0;
}