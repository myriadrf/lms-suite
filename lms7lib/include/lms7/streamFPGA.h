/**
@file 	lms7/streamFPGA.h
@author	Lime Microsystems
@brief 	Functions for configuring Stream FPGA
*/

#pragma once
#include <lms7/Config.h>
class ConnectionManager;

LMS7_API int ConfigurePLL(ConnectionManager *serPort, const float fOutTx_MHz, const float fOutRx_MHz, const float phaseShift_deg);
