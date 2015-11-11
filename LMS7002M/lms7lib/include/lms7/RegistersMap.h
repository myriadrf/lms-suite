/**
@file	RegistersMap.h
@author	Lime Microsystems
@brief	Header for RegistersMap.cpp
*/

#ifndef LMS7002_REGISTERS_MAP_H
#define LMS7002_REGISTERS_MAP_H

#include "ControlParameters.h"
#include "MessageLog.h"
#include <string>
#include <map>

class ConnectionManager;

enum LMS_MODULES
{
    UC = 0, LIME_LIGHT, AFE, BIAS, XBUF, CGEN, LDO, BIST, CDS, TRF, TBB, RFE, RBB, SXRSXT, TxTSP, TxNCO, RxTSP, RxNCO, LMS_MODULES_COUNT
};

/** @brief Defines register test modules and address spaces
*/
struct RegTestPlan
{
    RegTestPlan() : name("unnamed"), startAddr(0), endAddr(0), onlyUsedAddresses(true) {};
    RegTestPlan(const std::string sname, const unsigned short saddr, const unsigned short eaddr, const bool onlyUsed) :
        name(sname), startAddr(saddr), endAddr(eaddr), onlyUsedAddresses(onlyUsed) {};
    RegTestPlan(const RegTestPlan &reg)
    {
        name = reg.name;
        startAddr = reg.startAddr;
        endAddr = reg.endAddr;
        onlyUsedAddresses = reg.onlyUsedAddresses;
    };
    std::string name;
    unsigned short startAddr;
    unsigned short endAddr;
    bool onlyUsedAddresses;
};

/** @brief Defines memory register parameters
*/
struct MemoryRegister
{
    MemoryRegister() : address(0), value(0), defaultValue(0), mask(0xFFFF) {};
	unsigned short address;
	unsigned short value;
	unsigned short defaultValue;
	unsigned short mask;
};

/** @brief Defines parameters used to write and read bits from memory registers
*/
struct ControlParameter
{
    ControlParameter()
    {
        m_name = "";
        address = 0xFFFF;
        defValue = 0;
        bitCount = 0;
        LSBpos = 0;
        multichannel = false;
        readonly = false;
        inverted = false;
    };
    void Set(unsigned short addr, unsigned short defaultValue, char bitsCount, char lsb_pos, bool multiChannel = false, std::string name = "UNDEFINED")
    {
        m_name = name;
        address = addr;
        defValue = defaultValue;
        bitCount = bitsCount;
        if(bitCount == 0)
            MessageLog::getInstance()->write("Registers map: initializing parameter with 0 bits.\n");
        LSBpos = lsb_pos;
        if(LSBpos > 15 || LSBpos < 0)
            MessageLog::getInstance()->write("Registers map: initializing parameter with bad LSB.\n");
        multichannel = multiChannel;
    }
    std::string m_name;
	unsigned short address;
	unsigned short defValue;
	unsigned char bitCount;
	unsigned char LSBpos;
	bool multichannel;
	bool readonly;
	bool inverted;
};

/** @class RegistersMap
    @brief Class used for manipulating and storing memory registers
*/
class RegistersMap
{
public:
    RegTestPlan m_modulesInfo[LMS_MODULES_COUNT];
    RegistersMap( ConnectionManager *pConMng);
    ~RegistersMap();

    bool RegisterTest();
    int RegisterTestBatch(const std::string name, const unsigned short addr1, const unsigned short addr2, const unsigned short pattern, const bool onlyUsed = true);
    int RegisterTestSimple(const std::string name, const unsigned short addr1, const unsigned short addr2, const unsigned short pattern, const bool onlyUsed = true);
    void CancelRegisterTest();

    bool LoadFromFile(const std::string filename);
    bool LoadFromStream(std::ifstream &fin);
    bool SaveToFile(const std::string filename);
    bool SaveToStream(std::ofstream &fout);

    bool SetRegisterValue( unsigned short address, unsigned short value);
	unsigned short GetRegisterValue( unsigned short address, bool fromChip = false, bool updateLocal = true);

	bool SetParameterValue( LMS7002_Parameter param, unsigned long value);
	unsigned long GetParameterValue( LMS7002_Parameter param, bool fromChip = false, bool updateLocal = true);

	const ControlParameter getParameterInfo(const LMS7002_Parameter param );
	MemoryRegister getRegisterInfo(const unsigned channel, const unsigned short address) const;

    bool DownloadToHex(const std::string filename);

	bool DownloadAll();
	void SetAutoDownload(bool upload);
	bool GetAutoDownload() const;
	void SetAutoUpload(bool upload);
	bool GetAutoUpload() const;
	bool UploadAll();

	void SetDefaultValues();
	void InitializeControlParameters();

	void SelectConfigChannel(int channel, bool configAll);
	void RestoreLastSelectedChannel();
    int GetConfigChannel() const;
    bool GetConfigAll() const;

    std::map<unsigned short, unsigned short> GetRegistersValues(int channel);
    unsigned short GetRegisterMask(unsigned short addr) const;

    void StashRegisters()
    {
        stash[0] = m_registers[0];
        stash[1] = m_registers[1];
    }
    void RestoreRegisters()
    {
        m_registers[0] = stash[0];
        m_registers[1] = stash[1];
    }

    std::map<unsigned short, MemoryRegister> StashRegisters(int ch)
    {
        ch = ch & 0x1;
        return m_registers[ch];
    }
    void RestoreRegisters(int ch, const std::map<unsigned short, MemoryRegister> &registers)
    {
        m_registers[ch & 0x01] = registers;
    }

protected:
    int TestRegistersWithinRange(const std::string name, unsigned short addr1, unsigned short addr2, bool onlyUsed = true);
    bool CheckForOverlays();
    ConnectionManager *m_serPort; /// connection manager used for data writing and reading
    std::map<unsigned short, MemoryRegister> m_registers[2]; /// memory for each channel
    ControlParameter m_parameters[LMS_PARAMETER_COUNT]; /// All available parameters
    int m_activeChannel; /// currently used channel for configuring
    int m_lastActiveChannel;
    bool m_lastConfigAll;

    static const int m_channelCount = 2;

    bool m_autoUpload; /// when enabled each parameter change will be written immediately
    bool m_autoDownload; /// when enabled each parameter value will be read from chip
    bool m_configAllChannels; /// enables data writing to all channels
    bool m_cancelRegisterTest; /// stops registers testing

    ///used to backup register values
    std::map<unsigned short, MemoryRegister> stash[2];
};

#endif

