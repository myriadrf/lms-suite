/**
@file 	CommonUtilities.cpp
@author	Lime Microsystems
@brief 	various common utility functions used by all modules
*/

#include <lms7/CommonUtilities.h>
#include <sstream>
#include <iomanip>

#ifndef __unix__
    #include <windows.h>
#else
    #include <unistd.h>
    #include <sys/time.h>
#endif // LINUX

#include <stdio.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

/** @brief Sleeps for given amount of milliseconds
*/
void lms7::milSleep(unsigned int miliseconds)
{
#ifndef __unix__
    Sleep(miliseconds);
#else
    usleep(miliseconds*1000);
#endif
}

/** @brief Returns number of miliseconds since system was started
    @return number of miliseconds
*/
long lms7::getMilis()
{
#ifndef __unix__
    return GetTickCount();
#else
    struct timeval tv;
    gettimeofday(&tv, NULL);

    double time_in_mill = (tv.tv_sec)*1000 + (tv.tv_usec)/1000;
    return time_in_mill;
#endif // LINUX
}

/** @brief Converts given hex string to int
*/
int lms7::hex2int(const string hex)
{
    return (int)strtol(hex.c_str(), NULL, 0);
}

/** @brief Converts given integer to hex string with prefix 0x
    @param i integer to convert
    @param sizeBytes number of bytes to print
*/
string lms7::short2hex(unsigned short i)
{
    string str;
    char ctemp[16];
    sprintf(ctemp, "0x%04X", i);
    str = ctemp;
    return str;
}

/** @brief Converts given integer to hex string
    @param i integer to convert
    @param sizeBytes number of bytes to print
*/
string lms7::int2hex(int i, int sizeBytes)
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
string lms7::uint2hex(unsigned int i, int sizeBytes)
{
    std::stringstream stream;
    stream << std::setfill ('0') << std::setw(2*sizeBytes) << std::hex << i;
    return stream.str();
}

/** @brief Convert from two's complement to combo box index
    @param twosCompl two's complement number bits
    @return value index
*/
int lms7::twoComplementToIndex(unsigned int twosCompl, int bitCount)
{
    int index = 0;
    index = (twosCompl << (sizeof(int)*8-bitCount) >> (sizeof(int)*8-bitCount));
    index = index + pow(2.0, bitCount-1);
    return index;
}

unsigned int lms7::indexToTwoComplement(int index, int bitCount)
{
    int number = index - pow(2.0, bitCount-1);
    unsigned int mask = ~(0xFFFFFFFF << bitCount);
    unsigned int result = 0;
    result = number & mask;
    return result;
}

/** @brief Returns most repeated value, if all different returns first one
*/
unsigned char lms7::bestOfThree(const unsigned char A, const unsigned char B, const unsigned char C)
{
    if(A == B || A == C)
        return A;
    else if(B == C)
        return B;
    return A;
}
