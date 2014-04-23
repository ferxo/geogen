#pragma once

#include "../Number.hpp"
#include "TypeDefinition.hpp"
#include "VirtualMachine.hpp"
#include "PrimitiveObject.hpp"
#include "..\InternalErrorException.hpp"

namespace geogen
{
	namespace runtime
	{
		typedef PrimitiveObject<Number> NumberObject;

		class NullTypeDefinition : public TypeDefinition
		{
		public:
			NullTypeDefinition() : TypeDefinition("null") {}

			virtual DynamicObject* Copy(VirtualMachine* vm, DynamicObject* a) const
			{
				return a;
			};
		};
	}
}