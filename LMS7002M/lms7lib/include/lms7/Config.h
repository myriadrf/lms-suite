/**
@file 	lms7/Config.h
@author	Lime Microsystems
@brief 	Compile-time configuration and compatibility macros.
*/

#include <ciso646>

#ifdef _MSC_VER
  #ifndef _USE_MATH_DEFINES
    #define _USE_MATH_DEFINES //math.h M_* constants
  #endif //_USE_MATH_DEFINES
#endif //_MSC_VER
