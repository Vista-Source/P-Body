#pragma once

#include <vector>
#include "ICSharpBackend.h"
#include "PBodyInstance.h"
#include "PBodyAPI.h"

class PBody_API PBody
{
public:
	static void LoadCSharpBackend(ICSharpBackend* backend);
	static ICSharpBackend* GetLoadedBackend();
	static void LoadAssembly(const char* assemblyPath);
	static void UnloadAssembly(const char* assemblyPath);
	static MethodReturnValue RunCSharpMethod(const char* methodNamespace);
	static PBodyInstance* CreateInstance(const char* typeNamespace);
private:
	static ICSharpBackend* loadedBackend;

};

