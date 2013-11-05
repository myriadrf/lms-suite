#ifndef SI5351C_MODULE
#define SI5351C_MODULE

#include <stdio.h>
#include <string>
using namespace std;
//---------------------------------------------------------------------------

enum eSi_CLOCK_INPUT
{
    Si_CLKIN,
    Si_XTAL,
    Si_CMOS
};

struct Si5351_Channel
{
    int outputDivider;
    float outputFreqMHz;
    float multisynthDivider;
    int pllSource;
    float phaseOffset;
    bool powered;
    bool inverted;
};

struct Si5351_PLL
{
    float inputFreqMHz;
    float PFD_MHz;
    float VCO_MHz;
    float feedbackDivider;
};

class ConnectionManager;
class Si5351C
{
public:
	Si5351C();
	~Si5351C();
	void Initialize(ConnectionManager *mng);
	bool LoadRegValuesFromFile(string FName);

    void SetPLL(unsigned char id, float CLKIN_MHz);
    void SetClock(unsigned char id, float fOut_MHz, bool enabled = true, bool inverted = false);

	void UploadConfiguration();
	bool ConfigureClocks();
	void Reset();
private:
    ConnectionManager *device;

    Si5351_PLL m_PLLA;
    Si5351_PLL m_PLLB;

	static const unsigned char m_defaultConfiguration[];
	unsigned char m_newConfiguration[255];

	Si5351_Channel clk_channels[8];
};

#endif // SI5351C_MODULE
