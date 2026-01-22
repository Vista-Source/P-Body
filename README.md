# P-Body
Vista Source's solution for hosting .NET via the Source SDK.

*NOTE: This is a fork of [NetLeaf](https://github.com/Tweety-Lab/NetLeaf) designed for easy integration within the Source SDK*

## Adding to the SDK

### VPC
1. Navigate to the project .vpc script you want to add P-Body to (i.e., client_hl2mp.vpc)
2. Add `$Include "$SRCDIR\pbody\pbody.vpc"` to the .vpc header
3. Run `createallprojects.bat`
4. Build!

## NetLeaf

NetLeaf allows simple and fast .NET C# Hosting from C++ Code through a handful of easy to understand methods.

![License](https://img.shields.io/badge/License-MIT-blue) ![Release](https://img.shields.io/badge/Release-V1.0.0-green)

## Features

| Feature            | Supported |
|--------------------|-----------|
| Class Instances     | ✔️         |
| Method Running     | ✔️         |
| Method Arguments   | ✔️         |
| Method Return Values | ✔️       |

NetLeaf utilises the .NET Runtime to support .NET 9.0.0 by default.

## Getting Started
Once you have NetLeaf installed and `PBody.h` included in your file, you can get started with just a few calls.

**Load NetLeaf with a .NET Runtime backend:**
```C++
#include "PBody/DotNetBackend.h"
PBody::LoadCSharpBackend(new DotNetBackend());
```

**Load a C# Assembly:**
```C++
PBody::LoadAssembly("AssemblyName.dll");
```

**Run a Static C# Method:**
```C++
PBody::RunCSharpMethod("Namespace.ClassName.MethodName()");
```

**Create an Instance of a C# Class:**
```C++
PBody::CreateInstance("Namespace.ClassName");
```

**Create an Instance and run one of it's Methods:**
```C++
PBodyInstance* instance = PBody::CreateInstance("Namespace.ClassName");
instance->RunMethod("MethodName()");
```
