#ifndef COEFFICIENT_FILE_PARSER_H
#define COEFFICIENT_FILE_PARSER_H

/*
--------------------------------------------------------------------------------
FILE:			CoefficientFileParser.h
DESCRIPTION:	Just group parser functions into the same namespace.
CONTENT:
AUTHOR:			Lime Microsystems
DATE:			Nov 25, 2013
REVISIONS:
--------------------------------------------------------------------------------
*/

namespace Parser
{
	bool IsBlank(char);
	bool IsDigit(char);
	int getint(FILE *, int *);
	int getcoeffs(const char *, int *, int);
	int getcoeffs2(const char *, int *, int *, int);
	void saveToFile(const char *, const int *, int);
}

#endif // COEFFICIENT_FILE_PARSER_H
