/**
@file 	lms7/CommonUtilities.h
@author Lime Microsystems
@brief 	Header for CommonUtilities.cpp
*/

#ifndef COMMON_UTILITIES_H
#define COMMON_UTILITIES_H

#include <lms7/Config.h>
#include <string>

/** @brief Common utility functions used by logic and GUI
*/

namespace lms7
{

LMS7_API void milSleep(unsigned int miliseconds);
LMS7_API long getMilis();
LMS7_API int hex2int(const std::string hex);
LMS7_API std::string short2hex(unsigned short i);
LMS7_API std::string int2hex(int i, int sizeBytes = 1);
LMS7_API std::string uint2hex(unsigned int i, int sizeBytes = 1);

LMS7_API int twoComplementToIndex(unsigned int twosCompl, int bitCount);
LMS7_API unsigned int indexToTwoComplement(int index, int bitCount);

/** @brief Returns most repeated value, if all different returns first one
*/
LMS7_API unsigned char bestOfThree(const unsigned char A, const unsigned char B, const unsigned char C);

}

#endif // COMMON_UTILITIES_H

