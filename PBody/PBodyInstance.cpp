#include "cbase.h"

#include "PBodyInstance.h"
#include "PBody.h"
#include <string>


PBodyInstance::PBodyInstance(const char* typeNamespace)
{
    std::string methodCall = "PBody.Bridge.InstanceFactory.CreateInstance(" + std::string(typeNamespace) + ")";
    instanceID = PBody::GetLoadedBackend()->RunMethod(methodCall.c_str()).UIntResult;
}

PBodyInstance::~PBodyInstance()
{
	std::string methodCall = "PBody.Bridge.InstanceFactory.DeleteInstance(" + std::to_string(instanceID) + ")";
	PBody::GetLoadedBackend()->RunMethod(methodCall.c_str());
}

MethodReturnValue PBodyInstance::RunMethod(const char* methodNamespace)
{
	std::string methodCall = "PBody.Bridge.InstanceFactory.RunInstanceMethod(" + std::to_string(instanceID) + ", " + std::string(methodNamespace) + ")";
	return PBody::GetLoadedBackend()->RunMethod(methodCall.c_str());
}