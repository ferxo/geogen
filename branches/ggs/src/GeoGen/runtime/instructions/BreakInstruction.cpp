#include "BreakInstruction.hpp"
#include "..\CodeBlockStackEntry.hpp"
#include "..\VirtualMachine.hpp"
#include "..\..\InternalErrorException.hpp"

using namespace std;
using namespace geogen::runtime;
using namespace geogen::runtime::instructions;

InstructionStepResult BreakInstruction::Step(VirtualMachine* vm) const
{
	stack<CodeBlockStackEntry>& codeBlockStack = vm->GetCallStack().top().GetCodeBlockStack();

	if (this->codeBlockCount > codeBlockStack.size())
	{
		throw InternalErrorException("Break was deeper than current code block stack.");
	}

	for (unsigned i = 0; i < this->codeBlockCount; i++)
	{
		codeBlockStack.pop();
	}

	return INSTRUCTION_STEP_RESULT_TYPE_BREAK;
}