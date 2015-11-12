/**
@file	LMS7002_Commands.cpp
@author	Lime Microsystems
@brief	enumerations of available LMS7002M commands and statuses
*/

#include <lms7/LMS7002M_Commands.h>

static const char  status_text[][32]= {"Undefined/Failure", "Completed", "Unknown command", "Busy", "Too many blocks", "Error", "Wrong order", "Resource denied"};

const char* lms7::status2string(const int status)
{
    if(status >= 0 && status < STATUS_COUNT)
        return status_text[status];
    else
        return "Unknown status";
}

static const char  adc_units_text[][8] = {"", "V", "A", "Ohm", "W"};

const char* lms7::adcUnits2string(const unsigned units)
{
	if (units < ADC_UNITS_COUNT)
		return adc_units_text[units];
	else
		return " unknown";
}
