#include "Si5351C.h"
#include "ConnectionManager.h"
#include <math.h>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

/// Splits float into fraction integers A + B/C
void realToFrac(const float real, int &A, int &B, int &C)
{
    A = (int)real;
    B = (int)((real - A) * 1048576 + 0.5);
    C = 1048576;

    int a = B;
    int b = C;
    int temp;
    while( b!= 0) // greatest common divider
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    B = B/a;
    C = C/a;
}

/// Default configuration
const unsigned char Si5351C::m_defaultConfiguration[] =
{ 0,0x00,
  1,0x00,
  2,0x08,
  3,0x00,
  4,0x00,
  5,0x00,
  6,0x00,
  7,0x00,
  8,0x00,
  9,0x00,
 10,0x00,
 11,0x00,
 12,0x00,
 13,0x00,
 14,0x00,
 15,0x04,
 16,0x4F,
 17,0x4F,
 18,0x4F,
 19,0x4F,
 20,0x4F,
 21,0x4F,
 22,0x0F,
 23,0x0F,
 24,0x00,
 25,0x00,
 26,0x00,
 27,0x80,
 28,0x00,
 29,0x0B,
 30,0x2F,
 31,0x00,
 32,0x00,
 33,0x00,
 34,0x00,
 35,0x00,
 36,0x00,
 37,0x00,
 38,0x00,
 39,0x00,
 40,0x00,
 41,0x00,
 42,0x00,
 43,0x01,
 44,0x00,
 45,0x0D,
 46,0x00,
 47,0x00,
 48,0x00,
 49,0x00,
 50,0x00,
 51,0x01,
 52,0x00,
 53,0x0D,
 54,0x00,
 55,0x00,
 56,0x00,
 57,0x00,
 58,0x00,
 59,0x01,
 60,0x00,
 61,0x0D,
 62,0x00,
 63,0x00,
 64,0x00,
 65,0x00,
 66,0x00,
 67,0x01,
 68,0x00,
 69,0x0D,
 70,0x00,
 71,0x00,
 72,0x00,
 73,0x00,
 74,0x00,
 75,0x01,
 76,0x00,
 77,0x0D,
 78,0x00,
 79,0x00,
 80,0x00,
 81,0x00,
 82,0x00,
 83,0x01,
 84,0x00,
 85,0x0D,
 86,0x00,
 87,0x00,
 88,0x00,
 89,0x00,
 90,0x1E,
 91,0x1E,
 92,0x00,
 93,0x00,
 94,0x00,
 95,0x00,
 96,0x00,
 97,0x00,
 98,0x00,
 99,0x00,
100,0x00,
101,0x00,
102,0x00,
103,0x00,
104,0x00,
105,0x00,
106,0x00,
107,0x00,
108,0x00,
109,0x00,
110,0x00,
111,0x00,
112,0x00,
113,0x00,
114,0x00,
115,0x00,
116,0x00,
117,0x00,
118,0x00,
119,0x00,
120,0x00,
121,0x00,
122,0x00,
123,0x00,
124,0x00,
125,0x00,
126,0x00,
127,0x00,
128,0x00,
129,0x00,
130,0x00,
131,0x00,
132,0x00,
133,0x00,
134,0x00,
135,0x00,
136,0x00,
137,0x00,
138,0x00,
139,0x00,
140,0x00,
141,0x00,
142,0x00,
143,0x00,
144,0x00,
145,0x00,
146,0x00,
147,0x00,
148,0x00,
149,0x00,
150,0x00,
151,0x00,
152,0x00,
153,0x00,
154,0x00,
155,0x00,
156,0x00,
157,0x00,
158,0x00,
159,0x00,
160,0x00,
161,0x00,
162,0x00,
163,0x00,
164,0x00,
165,0x00,
166,0x00,
167,0x00,
168,0x00,
169,0x00,
170,0x00,
171,0x00,
172,0x00,
173,0x00,
174,0x00,
175,0x00,
176,0x00,
177,0x00,
178,0x00,
179,0x00,
180,0x00,
181,0x30,
182,0x00,
183,0xD2,
184,0x60,
185,0x60,
186,0x00,
187,0xC0,
188,0x00,
189,0x00,
190,0x00,
191,0x00,
192,0x00,
193,0x00,
194,0x00,
195,0x00,
196,0x00,
197,0x00,
198,0x00,
199,0x00,
200,0x00,
201,0x00,
202,0x00,
203,0x00,
204,0x00,
205,0x00,
206,0x00,
207,0x00,
208,0x00,
209,0x00,
210,0x00,
211,0x00,
212,0x00,
213,0x00,
214,0x00,
215,0x00,
216,0x00,
217,0x00,
218,0x00,
219,0x00,
220,0x00,
221,0x0D,
222,0x00,
223,0x00,
224,0x00,
225,0x00,
226,0x00,
227,0x00,
228,0x00,
229,0x00,
230,0x00,
231,0x00,
232,0x00};

// ---------------------------------------------------------------------------
Si5351C::Si5351C()
{
    memset(m_newConfiguration, 0, 255);
    for(unsigned int i=0; i<sizeof(m_defaultConfiguration); i+=2)
    {
        m_newConfiguration[m_defaultConfiguration[i]] = m_defaultConfiguration[i+1];
    }
	device = NULL;
}
// ---------------------------------------------------------------------------

Si5351C::~Si5351C()
{

}

/** @brief Sends Configuration to Si5351C chip
*/
void Si5351C::UploadConfiguration()
{
    vector<unsigned char> out;
	if (!device)
    {
        //MessageLog::getInstance()->write("Si5351C - connection manager not set. Configuring aborted.\n", LOG_ERROR);
		return;
    }
    //Disable outputs
	out.push_back(3);
	out.push_back(0xFF);
	//Power down all output drivers
	for(int i=0; i<8; ++i)
    {
        out.push_back(16+i);
        out.push_back(0x80);
    }
	//write new configuration
	for (int i = 15; i <= 92; ++i)
	{
        out.push_back(i);
        out.push_back(m_newConfiguration[i]);
	}
	for (int i = 149; i <= 170; ++i)
	{
        out.push_back(i);
        out.push_back(m_newConfiguration[i]);
	}
	//apply soft reset
	out.push_back(177);
	out.push_back(0xAC);
    //Enabe desired outputs
	out.push_back(3);
	out.push_back(m_newConfiguration[3]);
	device->SendData(CMD_SI5351_WR, &out[0], out.size());
    //MessageLog::getInstance()->write("Si5351C - Configuration upload completed.\n", LOG_INFO);
}

// ---------------------------------------------------------------------------
/**
    @brief Sets connection manager to use for data transferring and configures Si5356A
    @param mng connection manager for data transferring
*/
void Si5351C::Initialize(ConnectionManager *mng)
{
	device = mng;
	//if (device == NULL)
        //MessageLog::getInstance()->write("Si5351C - Initializing without connection manager.\n", LOG_WARNING);
}

/**
    @brief Loads register values for Si5356A from file
    @param FName input filename
*/
bool Si5351C::LoadRegValuesFromFile(string FName)
{
    //cout << "loading register values" << endl;
    fstream fin;
    fin.open(FName.c_str(), ios::in);

    int len = 1024;
    char line[len];

    int addr;
    int value;

    while(!fin.eof())
    {
        fin.getline(line, len);
        if( line[0] == '#')
            continue;
        if( strcmp(line, "#END_PROFILE") == 0)
            break;

        sscanf(line, "%i,%x",&addr,&value);
        m_newConfiguration[addr] = value;
    }

    fin.close();
	return false;
};

/** @brief Modifies register map with clock settings
    @return true if success
*/
bool Si5351C::ConfigureClocks()
{
    stringstream ss;
    int MSNA_P1;
    int MSNA_P2;
    int MSNA_P3;

    eSi_CLOCK_INPUT m_PLLA_inputSource = Si_CLKIN;
    eSi_CLOCK_INPUT m_PLLB_inputSource = Si_CLKIN;

    float m_PLLx_InputFreq = m_PLLA.inputFreqMHz;

    float fVCO = 1;
    int CLKIN_DIV = 1;
    //PLL input range 10-40 MHz
    if(m_PLLx_InputFreq < 10)
    {
        //MessageLog::getInstance()->write("Si5351C - PLL input frequency < 10 MHz.\n", LOG_ERROR);
        return false;
    }
    else if(m_PLLx_InputFreq > 40) //need to set divider
    {
        for(int i=0; i<4; ++i)
            if(m_PLLx_InputFreq/CLKIN_DIV > 40)
                CLKIN_DIV = CLKIN_DIV << 2;
    }
    if(CLKIN_DIV > 8 || m_PLLx_InputFreq/CLKIN_DIV > 40)
    {
        //MessageLog::getInstance()->write("Si5351C - PLL input CLKDIV_IN > 8.\n", LOG_ERROR);
        return false;
    }

    unsigned int MS1_P1;
    unsigned int MS1_P2;
    unsigned int MS1_P3;

    unsigned int *MSX_P1 = &MS1_P1;
    unsigned int *MSX_P2 = &MS1_P2;
    unsigned int *MSX_P3 = &MS1_P3;

    int addr;
    m_newConfiguration[3] = 0;
    float foutmax = 0;
    for(int i=0; i<8; ++i)
    {
        if(clk_channels[i].outputFreqMHz > foutmax)
            foutmax = clk_channels[i].outputFreqMHz;
    }
    float Divider = 8;
    while( foutmax * Divider < 600 && foutmax * Divider < 900)
    {
        ++Divider;
        fVCO = foutmax * Divider;
    }

    for(int i=0; i<8; ++i)
    {
        m_newConfiguration[3] |= (!clk_channels[i].powered) << i;
        addr = 42+i*8;
        float fout = clk_channels[i].outputFreqMHz;// clk_configs[i].fOut_MHz;
        ss.clear();
        ss.str( string() );
        ss << "fOut = " << fout << " MHz" << endl;
        //MessageLog::getInstance()->write(ss.str(), LOG_WARNING);
        int DivA;
        int DivB;
        int DivC;
        float Divider;
        if(fout == 0) Divider = 8;
        else Divider = fVCO / fout;
        realToFrac(Divider, DivA, DivB, DivC);
        ss.clear();
        ss.str( string() );
        ss << "Si5351C : fOut ratio   a = " << DivA << "  b = " << DivB << "  c = " << DivC << endl;
        //MessageLog::getInstance()->write(ss.str(), LOG_WARNING);


        if( Divider < 6 || 1800 < Divider)
        {
            //MessageLog::getInstance()->write("Si5351C - Output multisynth divider is outside [6;1800] interval.", LOG_ERROR);
            return false;
        }
        if(fout <= 150)
        {
            *MSX_P1 = 128 * DivA + floor(128 * ( (float)DivB/DivC)) - 512;
            *MSX_P2 = 128 * DivB - DivC * floor( 128 * DivB/DivC );
            *MSX_P3 = DivC;

            m_newConfiguration[addr] = *MSX_P3 >> 8;
            m_newConfiguration[addr+1] = *MSX_P3;

            m_newConfiguration[addr+2] = 0;
            m_newConfiguration[addr+2] |= (*MSX_P1 >> 16 ) & 0x03;
            m_newConfiguration[addr+3] = *MSX_P1 >> 8;
            m_newConfiguration[addr+4] = *MSX_P1;

            m_newConfiguration[addr+5] = 0;
            m_newConfiguration[addr+5] = (*MSX_P2 >> 16) & 0x0F;
            m_newConfiguration[addr+5] |= (*MSX_P3 >> 16) << 4;

            m_newConfiguration[addr+6] = *MSX_P2;
            m_newConfiguration[addr+7] = *MSX_P2 >> 8;
        }
        else if( fout <= 160) // AVAILABLE ONLY ON 0-5 MULTISYNTHS
        {

        }
    }

    float fCLKIN = m_PLLx_InputFreq;
    float fVCO_divider = fVCO / fCLKIN;
    if(fVCO_divider < 15 || fVCO_divider > 90)
    {
        //MessageLog::getInstance()->write("Si5351C - VCO frequency divider out of range [15:90].\n", LOG_ERROR);
        return false;
    }
    if( fVCO < 600 || fVCO > 900)
    {
        //MessageLog::getInstance()->write("Si5351C - Can't calculate valid VCO frequency.\n", LOG_ERROR);
        return false;
    }
    ss.clear();
    ss.str(string());
    ss << "Si5351C : fVCO = " << fVCO << " MHz" << endl;
    //MessageLog::getInstance()->write(ss.str(), LOG_WARNING);

    //calculate MSNx_P1, MSNx_P2, MSNx_P3
    int *MSNx_P1;
    int *MSNx_P2;
    int *MSNx_P3;

    MSNx_P1 = &MSNA_P1;
    MSNx_P2 = &MSNA_P2;
    MSNx_P3 = &MSNA_P3;

    int DivA;
    int DivB;
    int DivC;
    Divider = fVCO_divider;
    realToFrac(Divider, DivA, DivB, DivC);
    ss.clear();
    ss.str( string() );
    ss << "Si5351C : fVCO ratio  a = " << DivA << "  b = " << DivB << "  c = " << DivC << endl;
    //MessageLog::getInstance()->write(ss.str(), LOG_WARNING);

    *MSNx_P1 = 128 * DivA + floor(128 * ( (float)DivB/DivC)) - 512;
    *MSNx_P2 = 128 * DivB - DivC * floor( 128 * DivB/DivC );
    *MSNx_P3 = DivC;

    m_newConfiguration[30] = MSNA_P1;
    m_newConfiguration[30-1] = MSNA_P1 >> 8;
    m_newConfiguration[30-2] = MSNA_P1 >> 16;

    m_newConfiguration[33] = MSNA_P2;
    m_newConfiguration[32] = MSNA_P2 >> 8;
    m_newConfiguration[31] = 0;
    m_newConfiguration[31] = (MSNA_P2 >> 16) & 0x0F;

    m_newConfiguration[31] |= (MSNA_P3 >> 16) << 4;
    m_newConfiguration[27] |= MSNA_P3;
    m_newConfiguration[26] |= MSNA_P3 >> 8;

    //CLK input divider
    unsigned char cbyte = 0;
    cbyte = (m_newConfiguration[15] & 0x3F) | ((int)log2(CLKIN_DIV) << 6);
    //PLLA source
    if(m_PLLA_inputSource == Si_CLKIN)
        cbyte |= 0x04;
    else
        cbyte |= 0x00;
    //PLLB source
    if(m_PLLB_inputSource == Si_CLKIN)
        cbyte |= 0x08;
    else
        cbyte |= 0x00;
    m_newConfiguration[15] = cbyte;



    return true;
}

void Si5351C::SetClock(unsigned char id, float fOut_MHz, bool enabled, bool inverted)
{
    if( id < 8)
    {
        if(fOut_MHz < 0.008 || fOut_MHz > 160)
        {
            stringstream ss;
            ss << "Si5351C - CLK" << (int)id << " output frequency must be between 8kHz and 160MHz. fOut_MHz = " << fOut_MHz << endl;
            //MessageLog::getInstance()->write(ss.str(), LOG_ERROR);
            return;
        }
        clk_channels[id].powered = enabled;
        clk_channels[id].inverted = inverted;
        clk_channels[id].outputFreqMHz = fOut_MHz;
    }
}

void Si5351C::SetPLL(unsigned char id, float CLKIN_MHz)
{
    if( id == 0)
    {
        m_PLLA.inputFreqMHz = CLKIN_MHz;
    }
    if( id == 1)
    {
        m_PLLB.inputFreqMHz = CLKIN_MHz;
    }
}

void Si5351C::Reset()
{
    memset(m_newConfiguration, 0, 255);
    for(unsigned int i=0; i<sizeof(m_defaultConfiguration); i+=2)
    {
        m_newConfiguration[m_defaultConfiguration[i]] = m_defaultConfiguration[i+1];
    }
}
