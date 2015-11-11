Primary goals of the re-factor:

Separate out hardware specific hooks and graphical specific hooks
from the main LMS7 support library. LMS7 support should be as
minimalistic as possible to appeal to the widest user-base.

Re-factor thoughts and TODO list:

Leave lms7suite/ alone as a reference.
This directory will be gradually filled in from lms7suite/
with new library files, algorithms, various chip support,
a WX GUI support library, and possible GUI application,

The GUI application itself should be part of a hardware project
which glues together LMS7 driver, drivers for other on-board chips,
and the WX GUI support library for the evaluation software.

New directory structure:

* There will be a main library for the LMS7 driver
  that looks much like the current controlLogic directory.
  This library will provide an entry point for instantiating
  the driver object to control the LMS7,
  shared calibration algorithms which can be used
  in a stand-alone fashion to store calibration tables,
  and support for other chips that accompany official eval products.

* The C bindings will provide a C interface based on the LMS7002M-driver project.
  These bindings will share the calibration algorithms found in the main library.

* A separate directory will provide the graphical support library.
  It will compile against the LMS7 driver library in C++,
  and export several functions to invoke the GUI.

Outside of this directory structure:

* To support specific hardware (STREAM board for example).
  Another directory will incorporate the STREAM specific FPGA project,
  firmware, and any hardware-specific glue needed to run
  the LMS7 evaluation app using the GUI library.

* In addition, the STREAM board will provide a Soapy SDR
  example/demonstration project to show how the LMS7 driver
  can be integrated into a simple control + stream wrapper
  to be used with a vast ecosystem of SDR software.
