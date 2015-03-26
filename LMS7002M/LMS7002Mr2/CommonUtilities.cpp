// -----------------------------------------------------------------------------
// FILE: 		CommonUtilities.cpp
// DESCRIPTION: various common utility functions used by all modules
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#include "CommonUtilities.h"
#include <sstream>
#include <iomanip>

#ifndef LINUX
    #include <windows.h>
#else
    #include <unistd.h>
    #include <sys/time.h>
#endif // LINUX

#include <cmath>

/** @brief Sleeps for given amount of milliseconds
*/
void milSleep(unsigned int miliseconds)
{
#ifndef LINUX
    Sleep(miliseconds);
#else
    usleep(miliseconds*1000);
#endif
}

/** @brief Returns number of miliseconds since system was started
    @return number of miliseconds
*/
long getMilis()
{
#ifndef LINUX
    return GetTickCount();
#else
    struct timeval tv;
    gettimeofday(&tv, NULL);

    double time_in_mill = (tv.tv_sec)*1000 + (tv.tv_usec)/1000;
    return time_in_mill;
#endif // LINUX
}

/** @brief Converts given integer to hex string
    @param i integer to convert
    @param sizeBytes number of bytes to print
*/
string int2hex(int i, int sizeBytes)
{
    std::stringstream stream;
    for(int k=sizeBytes; k>0; --k)
        stream << std::setfill ('0') << std::setw(2) << std::hex << ((i >> (k-1)*8)&0xFF);
    return stream.str();
}

/** @brief Converts given integer to hex string
    @param i integer to convert
    @param sizeBytes number of bytes to print
*/
string uint2hex(unsigned int i, int sizeBytes)
{
    std::stringstream stream;
    stream << std::setfill ('0') << std::setw(2*sizeBytes) << std::hex << i;
    return stream.str();
}

/** @brief Convert from two's complement to combo box index
    @param twosCompl two's complement number bits
    @return value index
*/
int twoComplementToIndex(unsigned int twosCompl, int bitCount)
{
    int index = 0;
    index = (twosCompl << (sizeof(int)*8-bitCount) >> (sizeof(int)*8-bitCount));
    index = index + pow(2.0, bitCount-1);
    return index;
}

unsigned int indexToTwoComplement(int index, int bitCount)
{
    int number = index - pow(2.0, bitCount-1);
    unsigned int mask = ~(0xFFFFFFFF << bitCount);
    unsigned int result = 0;
    result = number & mask;
    return result;
}
