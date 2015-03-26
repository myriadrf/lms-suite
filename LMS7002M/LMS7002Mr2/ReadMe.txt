Lime Microsystems control_LMS7002 software

1. Archive content
	/bin - control_LMS7002 binaries.	
	/controlLogic - control logic source code.
	/controlPanelGUI - User interface source code.
	
2. Description
	This software is designed to control LMS7002M chip through COM port.

3. Compiling
	This project is made using Codeblocks IDE with GCC compiler. To compile this
	software wxWidgets 3.0.0 library is required.
	
	Before compiling, in project build options set compiler, linker and resource
	compiler search paths to wxWidgets library directories.

	Compiler : ...\wxWidgets-3.0.0\lib\gcc_lib\mswu
	Linker : ...\wxWidgets-3.0.0\lib\gcc_lib
	Resource compiler : ...\wxWidgets-3.0.0\lib\gcc_lib\mswu
	
	Choose Debug or Release target and build project.

