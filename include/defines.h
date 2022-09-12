#ifndef _defines_h_
#define _defines_h_

// Generic helper definitions for shared library support
#if defined _WIN32 || defined WIN32 || defined X64 || defined  _WINDLL || defined __CYGWIN__
    #if defined ASPOSE_DLL_EXPORT_SDK 
        #define ASPOSE_DLL_EXPORT __declspec(dllexport)
    #else
        #define ASPOSE_DLL_EXPORT __declspec(dllimport)
    #endif
#elif __GNUC__ >= 4
    #define ASPOSE_DLL_EXPORT __attribute__ ((visibility ("default")))
#else
    #define ASPOSE_DLL_EXPORT
#endif

#endif //_defines_h_