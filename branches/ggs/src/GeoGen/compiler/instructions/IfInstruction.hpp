#pragma once

#include "Instruction.hpp"
#include "../CodeBlock.hpp"

namespace geogen 
{
	namespace compiler 
	{
		namespace instructions
		{
			class IfInstruction : public Instruction
			{
			private:
				CodeBlock ifBranchCodeBlock;
				CodeBlock elseBranchCodeBlock;
			public:				

				inline CodeBlock& GetIfBranchCodeBlock() { return this->ifBranchCodeBlock; };
				inline CodeBlock const& GetIfBranchCodeBlock() const { return this->ifBranchCodeBlock; };
				
				inline CodeBlock& GetElseBranchCodeBlock() { return this->elseBranchCodeBlock; };
				inline CodeBlock const& GetElseBranchCodeBlock() const { return this->elseBranchCodeBlock; };

				virtual void Serialize(std::iostream& stream) const;
			};
		}
	}
}