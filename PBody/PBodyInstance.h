#pragma once
#include "CSharpInterop.h"
#include "PBodyAPI.h"

class PBody_API PBodyInstance
{
public:
	PBodyInstance(const char* typeNamespace);
	~PBodyInstance();
	MethodReturnValue RunMethod(const char* methodName);
private:
	uint32_t instanceID;
};

