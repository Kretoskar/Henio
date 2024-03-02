#pragma once

#ifdef HENIO_PLATFORM_WINDOWS
    #ifdef HENIO_BUILD_DLL
        #define HENIO_API __declspec(dllexport)
    #else
        #define HENIO_API __declspec(dllimport)
    #endif
#else
    #error Henio only supports Windows.
#endif