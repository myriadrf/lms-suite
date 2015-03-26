// -----------------------------------------------------------------------------
// FILE: 		LMS7002M_Commands.h
// DESCRIPTION:	enumerations of available LMS7002M commands and statuses
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#ifndef LMS7002M_COMMANDS_H
#define LMS7002M_COMMANDS_H

const int LMS_RST_DEACTIVATE = 0;
const int LMS_RST_ACTIVATE = 1;
const int LMS_RST_PULSE = 2;

enum eLMS_DEV {LMS_DEV_UNKNOWN, LMS_DEV_EVB6, LMS_DEV_DIGIGREEN, LMS_DEV_DIGIRED, LMS_DEV_EVB7, LMS_DEV_ZIPPER, LMS_DEV_COUNT};
const char LMS_DEV_NAMES[][80] = { "UNKNOWN", "EVB6", "DigiGreen", "DigiRed", "EVB7", "ZIPPER" };

enum eCMD_LMS7002M
{
    CMD_GET_INFO	= 0x00,
    ///Writes data to SI5356 synthesizer via I2C
    CMD_SI5356_WR 	= 0x11,
    ///Reads data from SI5356 synthesizer via I2C
    CMD_SI5356_RD	= 0x12,
    ///Writes data to SI5351 synthesizer via I2C
    CMD_SI5351_WR = 0x13,
    ///Reads data from SI5351 synthesizer via I2C
    CMD_SI5351_RD = 0x14,
    ///Sets new LMS7002M chip’s RESET pin level (0, 1, pulse)
    CMD_LMS7002_RST	= 0x20,
    ///Writes data to LMS7002M chip via SPI
    CMD_LMS7002_WR	= 0x21,
    ///Reads data from LMS7002M chip via SPI
    CMD_LMS7002_RD	= 0x22,
    ///
    CMD_PROG_MCU = 0x2C,
    ///Writes data to ADF4002 chip via SPI
    CMD_ADF4002_WR	= 0x31
};

enum eCMD_STATUS
{
    STATUS_UNDEFINED,
    STATUS_COMPLETED_CMD,
    STATUS_UNKNOWN_CMD,
    STATUS_BUSY_CMD,
    STATUS_MANY_BLOCKS_CMD,
    STATUS_ERROR_CMD
};

#endif // LMS7002M_COMMANDS_H

