#ifndef COEFFICIENT_FILE_PARSER_H
#define COEFFICIENT_FILE_PARSER_H

/**
@file	lms7/CoefficientFileParser.h
@author	Lime Microsystems
@brief	Just group parser functions into the same namespace.
*/

#include <lms7/Config.h>

namespace Parser
{
	LMS7_API bool IsBlank(char);
	LMS7_API bool IsDigit(char);
	LMS7_API int getint(FILE *, int *);
	LMS7_API int getcoeffs(const char *, int *, int);
	LMS7_API int getcoeffs2(const char *, int *, int *, int);
	LMS7_API void saveToFile(const char *, const int *, int);
}

#endif // COEFFICIENT_FILE_PARSER_H
