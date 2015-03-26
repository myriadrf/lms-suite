// -----------------------------------------------------------------------------
// FILE: 		Algorithms.h
// DESCRIPTION:	Header for Algorithms.cpp
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

class ConnectionManager;
enum {MIMO_A, MIMO_B, MIMO_BOTH};

enum {//RBB Band_id
	RBB_1_4MHZ, RBB_3_0MHZ, RBB_5_0MHZ, RBB_10_0MHZ, RBB_15_0MHZ, RBB_20MHZ, //Low Band
	RBB_37_0MHZ, RBB_66_0MHZ, RBB_108_0MHZ, //High Band
	RBB_ALL
};

enum {//TBB Band_id
	TBB_11_0MHZ,//Low Band //not all
	TBB_18_5MHZ, TBB_38_0MHZ, TBB_54_0MHZ, //High Band
	TBB_ALL
};

/**
    @class Algorithms
    @brief Class containing all calibration and tuning algorithms
*/
class Algorithms
{
public:
    Algorithms(ConnectionManager *mng);
    ~Algorithms();
    void Modify_SPI_Reg_bits (unsigned short SPI_reg_addr, unsigned char MSB_bit, unsigned char LSB_bit, unsigned short new_bits_data);
    unsigned short Get_SPI_Reg_bits (unsigned short SPI_reg_addr, unsigned char MSB_bit, unsigned char LSB_bit);

    //Calibrated and corrected control values
    unsigned short RBB_CBANK[MIMO_BOTH][RBB_ALL];
    unsigned char RBB_RBANK[MIMO_BOTH], TBB_CBANK[MIMO_BOTH], TBB_RBANK[MIMO_BOTH][TBB_ALL];

    void MIMO_Ctrl (unsigned char ch);
    void VCO_CoarseTuning_SXT_SXR (float Fref_MHz, float Fvco_des_MHz, unsigned char ch);
    void VCO_CoarseTuning_CGEN (float Fref_MHz, float Fvco_des);
    float Resistor_calibration ();
    void Set_NCO_Freq (float Freq_MHz);

    //RBB
    void Calibration_LowBand_RBB (unsigned char ch);
    void Calibration_HighBand_RBB (unsigned char ch);

    //TBB
    void Calibration_LowBand_TBB (unsigned char ch);
    void Calibration_HighBand_TBB (unsigned char ch);

protected:
    void Set_cal_path_RBB (unsigned char path_no);
    void Set_cal_path_TBB (unsigned char path_no);
    void Algorithm_A_RBB();
    unsigned short Algorithm_B_RBB();
    void Algorithm_F_RBB(unsigned char Band_id);

    void Algorithm_A_TBB();
    unsigned short Algorithm_B_TBB();
    void Algorithm_C_TBB(unsigned char Band_id);
    void Algorithm_D_TBB(unsigned char Band_id);
    void Algorithm_E_TBB(unsigned char Band_id);
    ConnectionManager *m_serPort; ///Connection manager which will be used for data writing and reading
};

#endif // ALGORITHMS_h

