// -----------------------------------------------------------------------------
// FILE: 		CommonUtilities.h
// DESCRIPTION: Header for CommonUtilities.cpp
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#ifndef COMMON_UTILITIES_H
#define COMMON_UTILITIES_H

#include <string>
using namespace std;

/** @brief Common utility functions used by logic and GUI
*/

void milSleep(unsigned int miliseconds);
long getMilis();
string int2hex(int i, int sizeBytes = 1);
string uint2hex(unsigned int i, int sizeBytes = 1);

int twoComplementToIndex(unsigned int twosCompl, int bitCount);
unsigned int indexToTwoComplement(int index, int bitCount);

#endif // COMMON_UTILITIES_H

