/**
@file 	lms7/Config.h
@author	Lime Microsystems
@brief 	Compile-time configuration and compatibility macros.
*/

#pragma once

// http://gcc.gnu.org/wiki/Visibility
// Generic helper definitions for shared library support
#if defined _WIN32 || defined __CYGWIN__
  #define LMS7_HELPER_DLL_IMPORT __declspec(dllimport)
  #define LMS7_HELPER_DLL_EXPORT __declspec(dllexport)
  #define LMS7_HELPER_DLL_LOCAL
#else
  #if __GNUC__ >= 4
    #define LMS7_HELPER_DLL_IMPORT __attribute__ ((visibility ("default")))
    #define LMS7_HELPER_DLL_EXPORT __attribute__ ((visibility ("default")))
    #define LMS7_HELPER_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
  #else
    #define LMS7_HELPER_DLL_IMPORT
    #define LMS7_HELPER_DLL_EXPORT
    #define LMS7_HELPER_DLL_LOCAL
  #endif
#endif

// Now we use the generic helper definitions above to define LMS7_API and LMS7_LOCAL.
// LMS7_API is used for the public API symbols. It either DLL imports or DLL exports (or does nothing for static build)
// LMS7_LOCAL is used for non-api symbols.

#ifdef LMS7_DLL // defined if LMS7 is compiled as a DLL
  #ifdef LMS7_DLL_EXPORTS // defined if we are building the LMS7 DLL (instead of using it)
    #define LMS7_API LMS7_HELPER_DLL_EXPORT
    #define LMS7_EXTERN
  #else
    #define LMS7_API LMS7_HELPER_DLL_IMPORT
    #define LMS7_EXTERN extern
  #endif // LMS7_DLL_EXPORTS
  #define LMS7_LOCAL LMS7_HELPER_DLL_LOCAL
#else // LMS7_DLL is not defined: this means LMS7 is a static lib.
  #define LMS7_API
  #define LMS7_LOCAL
  #define LMS7_EXTERN
#endif // LMS7_DLL

#include <ciso646>

#ifdef _MSC_VER
  #ifndef _USE_MATH_DEFINES
    #define _USE_MATH_DEFINES //math.h M_* constants
  #endif //_USE_MATH_DEFINES
#endif //_MSC_VER
