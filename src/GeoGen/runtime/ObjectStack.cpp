#include "ObjectStack.hpp"
#include "DynamicObject.hpp"
#include "..\InternalErrorException.hpp"
#include "..\CodeLocation.hpp"
#include "StackOverflowException.hpp"

using namespace geogen;
using namespace geogen::runtime;

const unsigned ObjectStack::SIZE_LIMIT = 1000;

/*CodeBlockStack::~CodeBlockStack()
{
	for (const_iterator it = this->Begin(); it < this->End(); it++)
	{
		delete (*it);
	}
}*/

DynamicObject* ObjectStack::Top()
{
	if (this->stack.size() < 1)
	{
		throw InternalErrorException("Can't get top of empty code block stack.");
	}

	return this->stack.back();
}

void ObjectStack::Pop()
{
	if (this->stack.size() < 1)
	{
		throw InternalErrorException("Can't get top of empty code block stack.");
	}

	this->stack.pop_back();
}

void ObjectStack::Push(CodeLocation location, DynamicObject* object)
{	
	if (SIZE_LIMIT == this->stack.size())
	{
		throw StackOverflowException(GGE2503_ObjectStackOverflow, location, STACK_TYPE_OBJECT);
	}

	this->stack.push_back(object);
}

void ObjectStack::CheckSize(unsigned requiredSize)
{
	if (this->stack.size() < requiredSize)
	{
		throw InternalErrorException("Object stack has fewer items than required for current operation.");
	}
}

void ObjectStack::Serialize(std::iostream& stream) const
{
	for (const_iterator it = this->Begin(); it != this->End(); it++)
	{
		(*it)->Serialize(stream);
		stream << std::endl;
	}
}