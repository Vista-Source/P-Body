#include "cbase.h"

#include "PBody.h"
#include <iostream>

// Static member definition
ICSharpBackend* PBody::loadedBackend = nullptr;


void PBody::LoadAssembly(const char* assemblyPath)
{
    if (!loadedBackend) return;

    // Pass the assembly path without surrounding quotes
    std::string methodCall = "PBody.Bridge.Assemblies.LoadAssembly(" + std::string(assemblyPath) + ")";
    loadedBackend->RunMethod(methodCall.c_str());
}

void PBody::UnloadAssembly(const char* assemblyPath) 
{
	if (!loadedBackend) return;

	// Pass the assembly path without surrounding quotes
	std::string methodCall = "PBody.Bridge.Assemblies.UnloadAssembly(" + std::string(assemblyPath) + ")";
	loadedBackend->RunMethod(methodCall.c_str());
}

void PBody::LoadCSharpBackend(ICSharpBackend* backend) 
{
	// Store the backend instance
	loadedBackend = backend;

	// Initialize the backend
	loadedBackend->Initialize();
}

ICSharpBackend* PBody::GetLoadedBackend() 
{
	return loadedBackend;
}

MethodReturnValue PBody::RunCSharpMethod(const char* methodNamespace)
{
	// Call the method on the loaded backend
    if (loadedBackend)
    {
        return loadedBackend->RunMethod(methodNamespace);
	}
	else 
	{
		std::cerr << "Error: No CSharp backend loaded. Unable to run method: " << methodNamespace << std::endl;
		return MethodReturnValue{};
	}
}

PBodyInstance* PBody::CreateInstance(const char* typeNamespace) 
{
	return new PBodyInstance(typeNamespace);
}