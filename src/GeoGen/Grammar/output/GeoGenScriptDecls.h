/** \file
 *  This C header file was generated by $ANTLR version null
 *
 *     -  From the grammar source file : D:\\Users\\Matej\\Desktop\\GeoGen GGS\\src\\GeoGen\\Grammar\\GeoGenScriptDecls.g
 *     -                            On : 2013-11-30 21:33:18
 *     -           for the tree parser : GeoGenScriptDeclsTreeParser
 *
 * Editing it, at least manually, is not wise.
 *
 * C language generator and runtime by Jim Idle, jimi|hereisanat|idle|dotgoeshere|ws.
 *
 *
 * The tree parser 
GeoGenScriptDecls

has the callable functions (rules) shown below,
 * which will invoke the code for the associated rule in the source grammar
 * assuming that the input stream is pointing to a token/text stream that could begin
 * this rule.
 *
 * For instance if you call the first (topmost) rule in a parser grammar, you will
 * get the results of a full parse, but calling a rule half way through the grammar will
 * allow you to pass part of a full token stream to the parser, such as for syntax checking
 * in editors and so on.
 *
 * The parser entry points are called indirectly (by function pointer to function) via
 * a parser context typedef pGeoGenScriptDecls, which is returned from a call to GeoGenScriptDeclsNew().
 *
 * The methods in pGeoGenScriptDecls are  as follows:
 *
 *  - 
 void
      pGeoGenScriptDecls->script(pGeoGenScriptDecls)
 *  - 
 void
      pGeoGenScriptDecls->metadata(pGeoGenScriptDecls)
 *  - 
 void
      pGeoGenScriptDecls->keyValueCollection(pGeoGenScriptDecls)
 *  - 
 void
      pGeoGenScriptDecls->keyValuePair(pGeoGenScriptDecls)
 *  - 
 void
      pGeoGenScriptDecls->keyValueValue(pGeoGenScriptDecls)
 *  - 
 void
      pGeoGenScriptDecls->declaration(pGeoGenScriptDecls)
 *  - 
 void
      pGeoGenScriptDecls->enumDeclaration(pGeoGenScriptDecls)
 *  - 
 void
      pGeoGenScriptDecls->enumValues(pGeoGenScriptDecls)
 *  - 
 void
      pGeoGenScriptDecls->enumValue(pGeoGenScriptDecls)
 *  - 
 void
      pGeoGenScriptDecls->functionDeclaration(pGeoGenScriptDecls)
 *  - 
 void
      pGeoGenScriptDecls->formalParameters(pGeoGenScriptDecls)
 *  - 
 void
      pGeoGenScriptDecls->block(pGeoGenScriptDecls)
 *  - 
 void
      pGeoGenScriptDecls->statement(pGeoGenScriptDecls)
 *  - 
 void
      pGeoGenScriptDecls->variableDeclaration(pGeoGenScriptDecls)
 *  - 
 void
      pGeoGenScriptDecls->yieldStatement(pGeoGenScriptDecls)
 *  - 
 void
      pGeoGenScriptDecls->returnStatement(pGeoGenScriptDecls)
 *  - 
 void
      pGeoGenScriptDecls->whileStatement(pGeoGenScriptDecls)
 *  - 
 void
      pGeoGenScriptDecls->forStatement(pGeoGenScriptDecls)
 *  - 
 void
      pGeoGenScriptDecls->initExpression(pGeoGenScriptDecls)
 *  - 
 void
      pGeoGenScriptDecls->ifStatement(pGeoGenScriptDecls)
 *  - 
 void
      pGeoGenScriptDecls->switchStatement(pGeoGenScriptDecls)
 *  - 
 void
      pGeoGenScriptDecls->normalCase(pGeoGenScriptDecls)
 *  - 
 void
      pGeoGenScriptDecls->defaultCase(pGeoGenScriptDecls)
 *  - 
 void
      pGeoGenScriptDecls->expression(pGeoGenScriptDecls)
 *  - 
 void
      pGeoGenScriptDecls->unkeyedCollectionLiteral(pGeoGenScriptDecls)
 *  - 
 void
      pGeoGenScriptDecls->coordinateLiteral(pGeoGenScriptDecls)
 *  - 
 void
      pGeoGenScriptDecls->label(pGeoGenScriptDecls)
 *
 * The return type for any particular rule is of course determined by the source
 * grammar file.
 */
// [The "BSD license"]
// Copyright (c) 2005-2009 Jim Idle, Temporal Wave LLC
// http://www.temporal-wave.com
// http://www.linkedin.com/in/jimidle
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. The name of the author may not be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef	_GeoGenScriptDecls_H
#define _GeoGenScriptDecls_H
/* =============================================================================
 * Standard antlr3 C runtime definitions
 */
#include    <antlr3.h>

/* End of standard antlr 3 runtime definitions
 * =============================================================================
 */

	#include "../../GeoGen.hpp"
	using namespace geogen;
	using namespace geogen::compiler;


#ifdef __cplusplus
extern "C" {
#endif

// Forward declare the context typedef so that we can use it before it is
// properly defined. Delegators and delegates (from import statements) are
// interdependent and their context structures contain pointers to each other
// C only allows such things to be declared if you pre-declare the typedef.
//
typedef struct GeoGenScriptDecls_Ctx_struct GeoGenScriptDecls, * pGeoGenScriptDecls;



#ifdef	ANTLR3_WINDOWS
// Disable: Unreferenced parameter,							- Rules with parameters that are not used
//          constant conditional,							- ANTLR realizes that a prediction is always true (synpred usually)
//          initialized but unused variable					- tree rewrite variables declared but not needed
//          Unreferenced local variable						- lexer rule declares but does not always use _type
//          potentially unitialized variable used			- retval always returned from a rule
//			unreferenced local function has been removed	- susually getTokenNames or freeScope, they can go without warnigns
//
// These are only really displayed at warning level /W4 but that is the code ideal I am aiming at
// and the codegen must generate some of these warnings by necessity, apart from 4100, which is
// usually generated when a parser rule is given a parameter that it does not use. Mostly though
// this is a matter of orthogonality hence I disable that one.
//
#pragma warning( disable : 4100 )
#pragma warning( disable : 4101 )
#pragma warning( disable : 4127 )
#pragma warning( disable : 4189 )
#pragma warning( disable : 4505 )
#pragma warning( disable : 4701 )
#endif

/** Context tracking structure for 
GeoGenScriptDecls

 */
struct GeoGenScriptDecls_Ctx_struct
{
    /** Built in ANTLR3 context tracker contains all the generic elements
     *  required for context tracking.
     */
    pANTLR3_TREE_PARSER	    pTreeParser;


     void
     (*script)	(struct GeoGenScriptDecls_Ctx_struct * ctx);

     void
     (*metadata)	(struct GeoGenScriptDecls_Ctx_struct * ctx);

     void
     (*keyValueCollection)	(struct GeoGenScriptDecls_Ctx_struct * ctx);

     void
     (*keyValuePair)	(struct GeoGenScriptDecls_Ctx_struct * ctx);

     void
     (*keyValueValue)	(struct GeoGenScriptDecls_Ctx_struct * ctx);

     void
     (*declaration)	(struct GeoGenScriptDecls_Ctx_struct * ctx);

     void
     (*enumDeclaration)	(struct GeoGenScriptDecls_Ctx_struct * ctx);

     void
     (*enumValues)	(struct GeoGenScriptDecls_Ctx_struct * ctx);

     void
     (*enumValue)	(struct GeoGenScriptDecls_Ctx_struct * ctx);

     void
     (*functionDeclaration)	(struct GeoGenScriptDecls_Ctx_struct * ctx);

     void
     (*formalParameters)	(struct GeoGenScriptDecls_Ctx_struct * ctx);

     void
     (*block)	(struct GeoGenScriptDecls_Ctx_struct * ctx);

     void
     (*statement)	(struct GeoGenScriptDecls_Ctx_struct * ctx);

     void
     (*variableDeclaration)	(struct GeoGenScriptDecls_Ctx_struct * ctx);

     void
     (*yieldStatement)	(struct GeoGenScriptDecls_Ctx_struct * ctx);

     void
     (*returnStatement)	(struct GeoGenScriptDecls_Ctx_struct * ctx);

     void
     (*whileStatement)	(struct GeoGenScriptDecls_Ctx_struct * ctx);

     void
     (*forStatement)	(struct GeoGenScriptDecls_Ctx_struct * ctx);

     void
     (*initExpression)	(struct GeoGenScriptDecls_Ctx_struct * ctx);

     void
     (*ifStatement)	(struct GeoGenScriptDecls_Ctx_struct * ctx);

     void
     (*switchStatement)	(struct GeoGenScriptDecls_Ctx_struct * ctx);

     void
     (*normalCase)	(struct GeoGenScriptDecls_Ctx_struct * ctx);

     void
     (*defaultCase)	(struct GeoGenScriptDecls_Ctx_struct * ctx);

     void
     (*expression)	(struct GeoGenScriptDecls_Ctx_struct * ctx);

     void
     (*unkeyedCollectionLiteral)	(struct GeoGenScriptDecls_Ctx_struct * ctx);

     void
     (*coordinateLiteral)	(struct GeoGenScriptDecls_Ctx_struct * ctx);

     void
     (*label)	(struct GeoGenScriptDecls_Ctx_struct * ctx);
    // Delegated rules

    const char * (*getGrammarFileName)();
    void            (*reset)  (struct GeoGenScriptDecls_Ctx_struct * ctx);
    void	    (*free)   (struct GeoGenScriptDecls_Ctx_struct * ctx);

    	geogen::compiler::CompiledScript* compiledScript;

};

// Function protoypes for the constructor functions that external translation units
// such as delegators and delegates may wish to call.
//
ANTLR3_API pGeoGenScriptDecls GeoGenScriptDeclsNew         (
pANTLR3_COMMON_TREE_NODE_STREAM
 instream);
ANTLR3_API pGeoGenScriptDecls GeoGenScriptDeclsNewSSD      (
pANTLR3_COMMON_TREE_NODE_STREAM
 instream, pANTLR3_RECOGNIZER_SHARED_STATE state);

/** Symbolic definitions of all the tokens that the 
tree parser
 will work with.
 * \{
 *
 * Antlr will define EOF, but we can't use that as it it is too common in
 * in C header files and that would be confusing. There is no way to filter this out at the moment
 * so we just undef it here for now. That isn't the value we get back from C recognizers
 * anyway. We are looking for ANTLR3_TOKEN_EOF.
 */
#ifdef	EOF
#undef	EOF
#endif
#ifdef	Tokens
#undef	Tokens
#endif
#define EOF      -1
#define AS      4
#define AT      5
#define BLOCK      6
#define BREAK      7
#define CASE      8
#define COLLECTION      9
#define COLON      10
#define COMMA      11
#define COMMENT      12
#define CONDITION_EXPRESSION      13
#define CONTINUE      14
#define COORDINATE      15
#define DECLARATIONS      16
#define DEFAULT      17
#define ELSE      18
#define ENUM      19
#define ESC_SEQ      20
#define FALSE_LIT      21
#define FOR      22
#define FUNCTION      23
#define HEX_DIGIT      24
#define IDENTCHAIN      25
#define IDENTIFIER      26
#define IF      27
#define INCREMENT_EXPRESSION      28
#define INITIALIZATION_EXPRESSION      29
#define INTEGER      30
#define LEFT_BRACKET      31
#define LEFT_CURLY_BRACKET      32
#define LEFT_SQUARE_BRACKET      33
#define METADATA      34
#define NUMBER      35
#define OPERATOR_ASSIGN      36
#define OPERATOR_ASSIGN_AND      37
#define OPERATOR_ASSIGN_DIVIDE      38
#define OPERATOR_ASSIGN_LSHIFT      39
#define OPERATOR_ASSIGN_MINUS      40
#define OPERATOR_ASSIGN_MODULO      41
#define OPERATOR_ASSIGN_OR      42
#define OPERATOR_ASSIGN_PLUS      43
#define OPERATOR_ASSIGN_RSHIFT      44
#define OPERATOR_ASSIGN_TIMES      45
#define OPERATOR_ASSIGN_XOR      46
#define OPERATOR_BIT_AND      47
#define OPERATOR_BIT_OR      48
#define OPERATOR_BIT_XOR      49
#define OPERATOR_CALL      50
#define OPERATOR_DECREMENT      51
#define OPERATOR_DIVIDE      52
#define OPERATOR_DOT      53
#define OPERATOR_EQUAL_TO      54
#define OPERATOR_EXPR_IF      55
#define OPERATOR_GREATER_THAN      56
#define OPERATOR_GREATER_THAN_OR_EQUAL_TO      57
#define OPERATOR_INCREMENT      58
#define OPERATOR_IS      59
#define OPERATOR_LESS_THAN      60
#define OPERATOR_LESS_THAN_OR_EQUAL_TO      61
#define OPERATOR_LSHIFT      62
#define OPERATOR_MINUS      63
#define OPERATOR_MODULO      64
#define OPERATOR_NOT      65
#define OPERATOR_NOT_EQUAL_TO      66
#define OPERATOR_PLUS      67
#define OPERATOR_REL_AND      68
#define OPERATOR_REL_OR      69
#define OPERATOR_RSHIFT      70
#define OPERATOR_SUBSCRIPT      71
#define OPERATOR_TIMES      72
#define PARAMETERS      73
#define RETURN      74
#define RIGHT_BRACKET      75
#define RIGHT_SQUARE_BRACKET      76
#define RIGTH_CURLY_BRACKET      77
#define SCRIPT      78
#define SEMICOLON      79
#define STRING      80
#define SWITCH      81
#define TRUE_LIT      82
#define VAR      83
#define WHILE      84
#define WHITESPACE      85
#define YIELD      86
#ifdef	EOF
#undef	EOF
#define	EOF	ANTLR3_TOKEN_EOF
#endif

#ifndef TOKENSOURCE
#define TOKENSOURCE(lxr) lxr->pLexer->rec->state->tokSource
#endif

/* End of token definitions for GeoGenScriptDecls
 * =============================================================================
 */
/** } */

#ifdef __cplusplus
}
#endif

#endif

/* END - Note:Keep extra line feed to satisfy UNIX systems */
