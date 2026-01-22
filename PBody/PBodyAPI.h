#pragma once

#if defined(_WIN32)

#if defined(PBody_BUILD)
#define PBody_API __declspec(dllexport)
#else
#define PBody_API
#endif

#else
#define PBody_API
#endif