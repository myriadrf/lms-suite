#include "VCO_Data.h"
#include <math.h>

/** @brief Class constructor.
    Initialization of VCO frequencies, Min, Max
    PLL frequencies, threshold frequency is done there.
*/
VCO_Data::VCO_Data()
{
  //High VCO settings
  m_iVCOLn = 2;
  m_pdVCOL = new double[m_iVCOLn];
  m_pdVCOL[0] = 3600.000;
  m_pdVCOL[1] = 5000.000;

  //Middle VCO settings
  m_iVCOMn = 2;
  m_pdVCOM = new double[m_iVCOMn];
  m_pdVCOM[0] = 4800.000;
  m_pdVCOM[1] = 6600.000;

  //Low VCO settings
  m_iVCOHn = 2;
  m_pdVCOH = new double[m_iVCOHn];
  m_pdVCOH[0] = 6300.000;
  m_pdVCOH[1] = 7700.000;

  m_dRefF = 30.720;    //Reference frequency MHz
  //m_dMaxF = 3850000.0;//Max frequency
  m_dMaxF = m_pdVCOH[m_iVCOHn-1]/2.0;  //Max frequency MHz
  //m_dMinF = 28125.0;  //Min frequency MHz
  m_dMinF = m_pdVCOL[0]/128.0;
  m_dThrF = 5500.000;//Threshold frequency to switch additional divider

};

/** @brief Class destructor.
*/
VCO_Data::~VCO_Data()
{
  delete [] m_pdVCOH;
  delete [] m_pdVCOM;
  delete [] m_pdVCOL;
};

/**
* Find the greatest common divisor of 2 numbers
* See http://en.wikipedia.org/wiki/Greatest_common_divisor
*
* @param dDF Desireg frequency, MHz
* @param rdRF Real frequency according to parameters calculated, MHz
* @param Nint Integer division ratio (INT_SDM)
* @param Nfrac Fractional division ratio (FRAC_SDM)
* @param iVCO VCO index (SEL_VCO)
* @param Fvco VCO frequency, MHz
* @param iDInd Divider (real divider is 2^(iDInd+1)), (DIV_LOCH)
* @param iEnDiv2 Additional presaler control (EN_DIV2_DIVPROG)
*/
void VCO_Data::FreqParams(double dDF, double &rdRF, unsigned &Nint, unsigned &Nfrac, unsigned &iVCO, double &Fvco, unsigned &iDInd, unsigned &iEnDiv2)
{
  double dMul = 1;
  double dFvco;
  double dFrac;
  double realDF;

  //Check if it is possible to generate desired frequency.
  //Set to limiting values if not.
  if       (dDF > m_dMaxF) realDF = m_dMaxF;
  else if  (dDF < m_dMinF) realDF = m_dMinF;
  else                     realDF = dDF;

  //VCO selection
  //High VCO
  if     ((realDF >= (m_pdVCOH[0]/128.0)) && (realDF <  (m_pdVCOH[m_iVCOHn-1]/128.0))) { dMul = (double) 128.0; iDInd = 6; iVCO = 2; }
  else if((realDF >= (m_pdVCOH[0]/64.0))  && (realDF <  (m_pdVCOH[m_iVCOHn-1]/64.0)))  { dMul = (double) 64.0;  iDInd = 5; iVCO = 2; }
  else if((realDF >= (m_pdVCOH[0]/32.0))  && (realDF <  (m_pdVCOH[m_iVCOHn-1]/32.0)))  { dMul = (double) 32.0;  iDInd = 3; iVCO = 2; }
  else if((realDF >= (m_pdVCOH[0]/16.0))  && (realDF <  (m_pdVCOH[m_iVCOHn-1]/16.0)))  { dMul = (double) 16.0;  iDInd = 2; iVCO = 2; }
  else if((realDF >= (m_pdVCOH[0]/8.0))   && (realDF <  (m_pdVCOH[m_iVCOHn-1]/8.0)))   { dMul = (double) 8.0 ;  iDInd = 4; iVCO = 2; }
  else if((realDF >= (m_pdVCOH[0]/4.0))   && (realDF <  (m_pdVCOH[m_iVCOHn-1]/4.0)))   { dMul = (double) 4.0 ;  iDInd = 1; iVCO = 2; }
  else if((realDF >= (m_pdVCOH[0]/2.0))   && (realDF <  (m_pdVCOH[m_iVCOHn-1]/2.0)))   { dMul = (double) 2.0 ;  iDInd = 0; iVCO = 2; }

  //Middle VCO
  else if((realDF >= (m_pdVCOM[0]/128.0)) && (realDF <  (m_pdVCOM[m_iVCOMn-1]/128.0))) { dMul = (double) 128.0; iDInd = 6; iVCO = 1; }
  else if((realDF >= (m_pdVCOM[0]/64.0))  && (realDF <  (m_pdVCOM[m_iVCOMn-1]/64.0)))  { dMul = (double) 64.0;  iDInd = 5; iVCO = 1; }
  else if((realDF >= (m_pdVCOM[0]/32.0))  && (realDF <  (m_pdVCOM[m_iVCOMn-1]/32.0)))  { dMul = (double) 32.0;  iDInd = 3; iVCO = 1; }
  else if((realDF >= (m_pdVCOM[0]/16.0))  && (realDF <  (m_pdVCOM[m_iVCOMn-1]/16.0)))  { dMul = (double) 16.0;  iDInd = 2; iVCO = 1; }
  else if((realDF >= (m_pdVCOM[0]/8.0))   && (realDF <  (m_pdVCOM[m_iVCOMn-1]/8.0)))   { dMul = (double) 8.0 ;  iDInd = 4; iVCO = 1; }
  else if((realDF >= (m_pdVCOM[0]/4.0))   && (realDF <  (m_pdVCOM[m_iVCOMn-1]/4.0)))   { dMul = (double) 4.0 ;  iDInd = 1; iVCO = 1; }
  else if((realDF >= (m_pdVCOM[0]/2.0))   && (realDF <  (m_pdVCOM[m_iVCOMn-1]/2.0)))   { dMul = (double) 2.0 ;  iDInd = 0; iVCO = 1; }

  //Low VCO
  else if((realDF >= (m_pdVCOL[0]/128.0)) && (realDF <  (m_pdVCOL[m_iVCOLn-1]/128.0))) { dMul = (double) 128.0; iDInd = 6; iVCO = 0; }
  else if((realDF >= (m_pdVCOL[0]/64.0))  && (realDF <  (m_pdVCOL[m_iVCOLn-1]/64.0)))  { dMul = (double) 64.0;  iDInd = 5; iVCO = 0; }
  else if((realDF >= (m_pdVCOL[0]/32.0))  && (realDF <  (m_pdVCOL[m_iVCOLn-1]/32.0)))  { dMul = (double) 32.0;  iDInd = 3; iVCO = 0; }
  else if((realDF >= (m_pdVCOL[0]/16.0))  && (realDF <  (m_pdVCOL[m_iVCOLn-1]/16.0)))  { dMul = (double) 16.0;  iDInd = 2; iVCO = 0; }
  else if((realDF >= (m_pdVCOL[0]/8.0))   && (realDF <  (m_pdVCOL[m_iVCOLn-1]/8.0)))   { dMul = (double) 8.0 ;  iDInd = 4; iVCO = 0; }
  else if((realDF >= (m_pdVCOL[0]/4.0))   && (realDF <  (m_pdVCOL[m_iVCOLn-1]/4.0)))   { dMul = (double) 4.0 ;  iDInd = 1; iVCO = 0; }
  else if((realDF >= (m_pdVCOL[0]/2.0))   && (realDF <  (m_pdVCOL[m_iVCOLn-1]/2.0)))   { dMul = (double) 2.0 ;  iDInd = 0; iVCO = 0; }

  //Calculate VCO frequency
  dFvco = dMul * realDF;
  //Fvco = (unsigned)dFvco;
  Fvco = dFvco;

  //Additional presaler control
  if (dFvco > m_dThrF) iEnDiv2 = 1;
  else iEnDiv2 = 0;

  //Integer division
  Nint = unsigned(double(dFvco/(m_dRefF * pow(2.0, iEnDiv2)))) - 4;

  //Fractional division
  dFrac = dFvco/m_dRefF - unsigned(dFvco/m_dRefF);
  Nfrac = dFrac * pow(2, 20);

  //Calculate real frequency according to the calculated parameters
  rdRF = m_dRefF * (1.0/dMul) * (((double)Nint + (double)Nfrac/(double)pow(2, 20)) + 4.0) * (double)pow(2, iEnDiv2);

};

/** @brief Returns reference frequency in MHz
*/
double VCO_Data::GetReferenceFrequency() const
{
    return m_dRefF;
}
