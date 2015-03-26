#ifndef AUTO_VERSION_H
#define AUTO_VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "24";
	static const char MONTH[] = "03";
	static const char YEAR[] = "2014";
	static const char UBUNTU_VERSION_STYLE[] =  "14.03";
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 2;
	static const long MINOR  = 4;
	static const long BUILD  = 1849;
	static const long REVISION  = 4734;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 3877;
	#define RC_FILEVERSION 2,4,1849,4734
	#define RC_FILEVERSION_STRING "2, 4, 1849, 4734\0"
	static const char FULLVERSION_STRING [] = "2.4.1849.4734";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 74;
	

}
#endif //AUTO_VERSION_H
