#ifndef VCO_DATA_H
#define VCO_DATA_H

//---------------------------------------------------------------------------
class VCO_Data
{
private:
    double *m_pdVCOH; //High VCO frequencies, MHz
    unsigned m_iVCOHn;     //Length of m_pdVCOH
    double *m_pdVCOM; //Middle VCO frequencies, MHz
    unsigned m_iVCOMn;     //Length of m_pdVCOM
    double *m_pdVCOL; //Low VCO frequencies, MHz
    unsigned m_iVCOLn;     //Length of m_pdVCOL

    double m_dRefF;   //Reference frequency, MHz
    double m_dMaxF;   //Max frequency, MHz
    double m_dMinF;   //Min frequency, MHz
    double m_dThrF;   //Threshold frequency to switch additional divider, MHz

protected:

public:
    VCO_Data();
    ~VCO_Data();

    void FreqParams(double dDF, double &rdRF, unsigned &Nint, unsigned &Nfrac, unsigned &iVCO, double &Fvco, unsigned &iDInd, unsigned &iEnDiv2);
    double GetReferenceFrequency() const;
};

#endif // VCO_DATA_H
