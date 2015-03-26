// -----------------------------------------------------------------------------
// FILE: 		Algorithms.cpp
// DESCRIPTION:	calibration algorithms
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#include "Algorithms.h"
#include "ConnectionManager.h"

/** @brief Assigns connection manager for data transmission
*/
Algorithms::Algorithms(ConnectionManager *mng)
{
    m_serPort = mng;
}

Algorithms::~Algorithms()
{
}

/**
Function which replaces requested bits range in SPI register with given data.
    @param SPI_reg_addr: SPI register address
    @param MSB_bit range index
    @param LSB_bit range index
    @param new_bits_data new bits data which will be replace old data
*/

void Algorithms::Modify_SPI_Reg_bits (unsigned short SPI_reg_addr, unsigned char MSB_bit, unsigned char LSB_bit, unsigned short new_bits_data)
{
	unsigned short mask, SPI_reg_data;
	unsigned char bits_number;

	bits_number = MSB_bit - LSB_bit + 1;

	mask = 0xFFFF;

	//removing unnecessary bits from mask
	mask = mask << (16 - bits_number);
	mask = mask >> (16 - bits_number);

	new_bits_data &= mask; //mask new data

	new_bits_data = new_bits_data << LSB_bit; //shift new data

	mask = mask << LSB_bit; //shift mask
	mask =~ mask;//invert mask

	SPI_reg_data = m_serPort->mSPI_read (SPI_reg_addr); //read current SPI reg data

	SPI_reg_data &= mask;//clear bits
	SPI_reg_data |= new_bits_data; //set bits with new data

	m_serPort->mSPI_write(SPI_reg_addr, SPI_reg_data); //write modified data back to SPI reg
}

/**
Function, which returns requested bits range value from SPI register.

    @param SPI_reg_addr SPI register address
    @param MSB_bit range index
    @param LSB_bit range index
    @return Returned bits are placed from LSB.
*/
unsigned short Algorithms::Get_SPI_Reg_bits (unsigned short SPI_reg_addr, unsigned char MSB_bit, unsigned char LSB_bit)
{
	unsigned short bits, mask;
	unsigned char bits_number;

	bits_number = MSB_bit - LSB_bit + 1;

	mask = 0xFFFF;

	//removing unnecessary bits from mask
	mask = mask << (16 - bits_number);
	mask = mask >> (16 - bits_number);

	bits = m_serPort->mSPI_read (SPI_reg_addr); //read current data

	bits = bits >> LSB_bit; //shift bits to LSB

	bits &= mask; //mask bits

	return bits;
}

unsigned char MIMO_ch;
const float RBB_CalFreq[RBB_ALL] = {0.7, 1.5 , 2.5, 5.0, 7.5, 10.0, 18.5, 33.0, 54.0}; //half of bandwidth
const float TBB_CalFreq[TBB_ALL] = {18.5, 38.0, 54.0};

float fclk = 27; //pll clk

unsigned short LowFreqAmp;

/**
Selects MIMO channel. Channel have to be selected before calibration procedures starts. Only one channel can be selected at the same time.
    @param ch
        - 0 - A (SXR)
        - 1 - B (SXT)
*/
void Algorithms::MIMO_Ctrl (unsigned char ch)
{

/*
	01 - Channel A accessible only. Valid for SPI read/write
	10 - Channel B accessible only. Valid for SPI read/write
	11 - Channels A and B accessible. SPI write operation only (calibration will not work correctly)
*/
	Modify_SPI_Reg_bits (0x0040, 1, 0, ch + 1);
	MIMO_ch = ch; //save channel
}

/**
Function for SXT SXR VCO Coarse Tuning
Only one module  (SXT or SXR) can be tuned at same time!
    @param Fref_MHz reference frequency in MHz
    @param Fvco_des_MHz desired vco frequency in MHz
    @param ch channel
*/
void Algorithms::VCO_CoarseTuning_SXT_SXR (float Fref_MHz, float Fvco_des_MHz, unsigned char ch)
{
	unsigned short Nround;
	unsigned char i;

	MIMO_Ctrl(ch);//SXT SXR selection

	// Initialization
	Modify_SPI_Reg_bits (0x011C, 12, 12, 1); // 1) EN_COARSEPLL=1, a. VCO control voltage is switched to a DC =VDD/2
	Modify_SPI_Reg_bits (0x0121, 0, 0, 0); // 2) COARSE_START=0
	Modify_SPI_Reg_bits (0x011C, 9, 9, 1); // 3) EN_INTONLY_SDM=1
	Modify_SPI_Reg_bits (0x011C, 14, 14, 1); // 4) SHORT_NOISEFIL=1 SPDUP_VCO_ Short the noise filter resistor to speed up the settling time
	Nround = (unsigned short)(4*Fvco_des_MHz/Fref_MHz+0.5); // 5)	Nround=round(4*Fvco_des/Fref)
	Modify_SPI_Reg_bits (0x011D, 15, 0, 0); // 6) FRAC_SDM=0
	Modify_SPI_Reg_bits (0x011E, 3, 0, 0);
	Modify_SPI_Reg_bits (0x011E, 13, 4, (Nround-4)); // 7) INT_SDM=Nround-4
	Modify_SPI_Reg_bits (0x0121, 10, 3, 0); // 9)	Set SWC_VCO<7:0>=<00000000>
	i=7;// 10)	i=7

	// Loop Section
	while(1)
	{
		Modify_SPI_Reg_bits (0x0121, 3 + i, 3 + i, 1); // SWC_VCO<i>=1
		Modify_SPI_Reg_bits (0x0121, 0, 0, 1); // COARSE_START=1

		while ( Get_SPI_Reg_bits(0x0123, 15, 15) != 1 ); //wait till COARSE_STEPDONE=1

		if ( Get_SPI_Reg_bits(0x0123, 14, 14) == 1) //check CAORSEPLL_COMPO
		{
			Modify_SPI_Reg_bits (0x0121, 3 + i, 3 + i, 0); // SWC_VCO<i>=0
		}

		Modify_SPI_Reg_bits (0x0121, 0, 0, 0); // COARSE_START=0

		if(i==0) break;
		i--;
	}

	Modify_SPI_Reg_bits (0x011C, 12, 12, 0); // EN_COARSEPLL=0
	Modify_SPI_Reg_bits (0x011C, 9, 9, 0); // EN_INTONLY_SDM=0
	Modify_SPI_Reg_bits (0x011C, 14, 14, 0); // SHORT_NOISEFIL=0 SPDUP_VCO_ Short the noise filter resistor to speed up the settling time
}

/**
Function for CGEN VCO Coarse Tuning
    @param Fref_MHz reference frequency in MHz
    @param Fvco_des_MHz desired vco frequency in MHz
*/
void Algorithms::VCO_CoarseTuning_CGEN (float Fref_MHz, float Fvco_des_MHz)
{
	unsigned short Nround;
	unsigned char i;

	// Initialization
	Modify_SPI_Reg_bits (0x0086, 10, 10, 1); // 1) EN_COARSE_CKLGEN=1, a. VCO control voltage is switched to a DC =VDD/2
	Modify_SPI_Reg_bits (0x008B, 0, 0, 0); // 2) COARSE_START_CGEN=0
	Modify_SPI_Reg_bits (0x0086, 9, 9, 1); // 3) EN_INTONLY_SDM_CGEN=1
	Modify_SPI_Reg_bits (0x0086, 15, 15, 1); // 4) SHORT_NOISEFIL=1 SPDUP_VCO_CGEN Short the noise filter resistor to speed up the settling time
	Nround = (unsigned short)(4*Fvco_des_MHz/Fref_MHz+0.5); // 5)	Nround=round(4*Fvco_des/Fref)
	Modify_SPI_Reg_bits (0x0087, 15, 0, 0); // 6) FRAC_SDM_CGEN=0
	Modify_SPI_Reg_bits (0x0088, 3, 0, 0);
	Modify_SPI_Reg_bits (0x0088, 13, 4, (Nround-4)); // 7) INT_SDM_CGEN =Nround-4
	Modify_SPI_Reg_bits (0x008B, 8, 1, 0); // 9)	Set CSW_VCO_CGEN<7:0>=<00000000>
	i=7;// 10)	i=7

	// Loop Section
	while(1)
	{
		Modify_SPI_Reg_bits (0x008B, 1 + i, 1 + i, 1); // CSW_VCO_CGEN<i>=1
		Modify_SPI_Reg_bits (0x008B, 0, 0, 1); // COARSE_START_CGEN=1

		while ( Get_SPI_Reg_bits(0x008C, 15, 15) != 1 ); //wait till COARSE_STEPDONE_CGEN=1

		if ( Get_SPI_Reg_bits(0x008C, 14, 14) == 1) //check COARSEPLL_COMPO_CGEN
		{
			Modify_SPI_Reg_bits (0x008B, 1 + i, 1 + i, 0); // SWC_VCO<i>=0
		}

		Modify_SPI_Reg_bits (0x008B, 0, 0, 0); // 2) COARSE_START_CGEN=0

		if(i==0) break;
		i--;
	}

	Modify_SPI_Reg_bits (0x0086, 10, 10, 0); // 1) EN_COARSE_CKLGEN=0
	Modify_SPI_Reg_bits (0x0086, 9, 9, 0); // 3) EN_INTONLY_SDM_CGEN=0
	Modify_SPI_Reg_bits (0x0086, 15, 15, 0); // 4) SHORT_NOISEFIL=0 SPDUP_VCO_CGEN Short the noise filter resistor to speed up the settling time
}

float Algorithms::Resistor_calibration ()
{
	unsigned char RP_CALIB_BIAS, RP_CALIB_BIAS_cal;
	unsigned short BestValue, ADCOUT;
	float ratio;

	RP_CALIB_BIAS_cal = 16;
	RP_CALIB_BIAS = 0;
	Modify_SPI_Reg_bits (0x0084, 10, 6, RP_CALIB_BIAS); // write RP_CALIB_BIAS value
	Modify_SPI_Reg_bits (0x0084, 12, 11, 1); // MUX_BIAS_OUT = 1
	Modify_SPI_Reg_bits (0x040A, 13, 12, 1); // AGC Mode = 1 (RSSI mode)

	while (RP_CALIB_BIAS <= 31)
	{
		ADCOUT = Get_SPI_Reg_bits(0x040B, 15, 0); //RSSI value

		if(RP_CALIB_BIAS == 0)
		{
			BestValue = ADCOUT;
		}

		if ( ADCOUT < BestValue )
		{
			BestValue = ADCOUT;
			RP_CALIB_BIAS_cal = RP_CALIB_BIAS; //store calibrated value
		}

		RP_CALIB_BIAS++;
		Modify_SPI_Reg_bits (0x0084, 10, 6, RP_CALIB_BIAS); // write RP_CALIB_BIAS value
	}

	Modify_SPI_Reg_bits (0x0084, 10, 6, RP_CALIB_BIAS_cal); // set the control RP_CAL_BIAS to stored calibrated value
	ratio = 16/RP_CALIB_BIAS_cal; //calculate ratio

	return ratio;
}

// RBB
void Algorithms::Set_NCO_Freq (float Freq_MHz)
{
	unsigned long fcw;

	fcw = (unsigned long)((Freq_MHz*(2^32))/fclk);

	Modify_SPI_Reg_bits (0x0240, 10, 6, 0); //TX SEL[3:0] = 0 & MODE = 0

	Modify_SPI_Reg_bits (0x0242, 15, 0, (fcw >> 16)); //FCW0[31:16]: NCO frequency control word register 0. MSB part.
	Modify_SPI_Reg_bits (0x0243, 15, 0, fcw); //FCW0[15:0]: NCO frequency control word register 0. LSB part.
}

void Algorithms::Algorithm_A_RBB ()
{
	unsigned char R_CTL_LPF_RBB;

	R_CTL_LPF_RBB = 16; // default control value
	R_CTL_LPF_RBB = (unsigned char)(R_CTL_LPF_RBB * Resistor_calibration ()); // Multiply by ratio

	Modify_SPI_Reg_bits (0x0116, 15, 11, R_CTL_LPF_RBB);
	RBB_RBANK[MIMO_ch] = R_CTL_LPF_RBB; // Store RBANK Values (R_CTL_LPF_RBB)
}

unsigned short Algorithms::Algorithm_B_RBB ()
{
	unsigned short ADCOUT;
	unsigned char CG_IAMP_TBB, gain_inc;

	Set_NCO_Freq (0.1); // Set DAC output to 100kHz (0.1MHz) single tone.

	CG_IAMP_TBB = 24; //set nominal CG_IAMP_TBB value
	Modify_SPI_Reg_bits (0x0108, 15, 10, CG_IAMP_TBB);

	Modify_SPI_Reg_bits (0x040A, 13, 12, 1); // AGC Mode = 1 (RSSI mode)
	ADCOUT = Get_SPI_Reg_bits(0x040B, 15, 0); //RSSI value // Measure the output level at the ADC input

	if(ADCOUT < 52428) gain_inc = 1; //is it less then 80% of full scale swing (52428 (80% of 16 bits))
		else gain_inc = 0;

	while (1)
	{
		ADCOUT = Get_SPI_Reg_bits(0x040B, 15, 0); //RSSI value // Measure the output level at the ADC input

		if (gain_inc)
		{
			if(ADCOUT >= 52428) break;
		}
		else
		{
			if(ADCOUT <= 52428) break;
		}

		if( (CG_IAMP_TBB == 0) || (CG_IAMP_TBB == 63)) break; //gain limit reached

		if(gain_inc) CG_IAMP_TBB++;
			else CG_IAMP_TBB--;

		Modify_SPI_Reg_bits (0x0108, 15, 10, CG_IAMP_TBB); //write val to reg
	}

	return ADCOUT; // Record the exact value of the amplitude in “LowFreqAmp” for later on comparison.
}

void Algorithms::Algorithm_F_RBB (unsigned char Band_id)
{
	unsigned short ADCOUT, CONTROL;
	unsigned short LowFreqAmp;
	unsigned char low_band;

	Modify_SPI_Reg_bits (0x040A, 13, 12, 1); // AGC Mode = 1 (RSSI mode)

	if(Band_id <= RBB_20MHZ)
	{
		low_band = 1; // CONTROL=C_CTL_LPFL_RBB
		CONTROL = 0xFF; // Set the CONTROL to maximum value. This should bring the output cutt-off frequency to minimum.
	}
	else
	{
		low_band = 0; // CONTROL=C_CTL_LPFH_RBB
		CONTROL = 0x7FF; // Set the CONTROL to maximum value. This should bring the output cutt-off frequency to minimum.
	}

	if (low_band) Modify_SPI_Reg_bits (0x0117, 10, 0, CONTROL); // write to C_CTL_LPFL_RBB
		else Modify_SPI_Reg_bits (0x0116, 7, 0, CONTROL); // write to C_CTL_LPFH_RBB

	LowFreqAmp = Algorithm_B_RBB (); // Apply (Algorithm B).
	Set_NCO_Freq (RBB_CalFreq[Band_id]); // Apply a single tone frequency at “CalFreq”.

	while (1)
	{
		if (low_band) Modify_SPI_Reg_bits (0x0117, 10, 0, CONTROL); // write to C_CTL_LPFL_RBB
			else Modify_SPI_Reg_bits (0x0116, 7, 0, CONTROL); // write to C_CTL_LPFH_RBB

		ADCOUT = Get_SPI_Reg_bits(0x040B, 15, 0); //RSSI value // Measure the value of the amplitude at the ADC input. This value should be lower than “LowFreqAmp”.

		if (! (ADCOUT < LowFreqAmp)) break; //If it is lower than “LowFreqAmp” repeat cycle
		if (CONTROL == 0) break;
		CONTROL--; // Decrease the CONTROL value by one.
	}

	RBB_CBANK[MIMO_ch][Band_id] = CONTROL; // Store CBANK Values
}

void Algorithms::Set_cal_path_RBB (unsigned char path_no)
{
	switch (path_no)
	{
		case 7: // RX  LPF Low Section Verification
			// RBB Control Bits
			Modify_SPI_Reg_bits (0x010C, 1, 1, 1);//PD_TIA_RFE == 1
			Modify_SPI_Reg_bits (0x0115, 3, 3, 1);//PD_LPFH_RBB == 1
			Modify_SPI_Reg_bits (0x0115, 2, 2, 0);//PD_LPFL_RBB == 0
			Modify_SPI_Reg_bits (0x0115, 15, 15, 0);//EN_LB_LPFH_RBB == 0
			Modify_SPI_Reg_bits (0x0115, 14, 14, 1);//EN_LB_LPFL_RBB == 1
			Modify_SPI_Reg_bits (0x0118, 15, 13, 0);//INPUT_CTL_PGA_RBB == 0
			Modify_SPI_Reg_bits (0x0119, 15, 15, 1);//OSW_PGA_RBB == 1
			break;

		case 8: // RX  LPF High Section Verification
			// RBB Control Bits
			Modify_SPI_Reg_bits (0x010C, 1, 1, 1);//PD_TIA_RFE == 1
			Modify_SPI_Reg_bits (0x0115, 3, 3, 0);//PD_LPFH_RBB == 0
			Modify_SPI_Reg_bits (0x0115, 2, 2, 1);//PD_LPFL_RBB == 1
			Modify_SPI_Reg_bits (0x0115, 15, 15, 1);//EN_LB_LPFH_RBB == 1
			Modify_SPI_Reg_bits (0x0115, 14, 14, 0);//EN_LB_LPFL_RBB == 0
			Modify_SPI_Reg_bits (0x0118, 15, 13, 1);//INPUT_CTL_PGA_RBB == 1
			Modify_SPI_Reg_bits (0x0119, 15, 15, 1);//OSW_PGA_RBB == 1
			break;
	}

	// TBB Control Bits
	Modify_SPI_Reg_bits (0x010A, 15, 14, 0);//TSTIN_TBB == 0
	Modify_SPI_Reg_bits (0x0105, 4, 4, 0);//PD_LPFH_TBB == 0
	Modify_SPI_Reg_bits (0x0105, 14, 12, 1);//LOOPB_TBB<1:0> == 1
	Modify_SPI_Reg_bits (0x0105, 1, 1, 0);//(PD_LPFS5_TBB == 0 OR PD_LPFLAD_TBB == 0)  (pre-emphasis OFF)
}

void Algorithms::Calibration_LowBand_RBB (unsigned char ch)
{
	MIMO_Ctrl (ch);

	Algorithm_A_RBB (); // Aproximate resistor value for RBB RBANKS (Algorithm A)

	Set_cal_path_RBB (7); // Set control signals to path 7 (RX LowBand)

	Algorithm_B_RBB (); // Calibrate and Record the low frequency output amplitude (Algorithm B)

	Algorithm_F_RBB (RBB_1_4MHZ);// CalibrateByCap the output cuttoff frequency at 0,7 MHz and store
	Algorithm_F_RBB (RBB_3_0MHZ);// CalibrateByCap the output cuttoff frequency at 1,5 MHz MHz and store
	Algorithm_F_RBB (RBB_5_0MHZ);// CalibrateByCap the output cuttoff frequency at 2,5 MHz MHz and store
	Algorithm_F_RBB (RBB_10_0MHZ);// CalibrateByCap the output cuttoff frequency at 5 MHz MHz and store
	Algorithm_F_RBB (RBB_15_0MHZ);// CalibrateByCap the output cuttoff frequency at 7,5 MHz and store
	Algorithm_F_RBB (RBB_20MHZ);// CalibrateByCap the output cuttoff frequency at 10 MHz MHz and store
}

void Algorithms::Calibration_HighBand_RBB (unsigned char ch)
{
	MIMO_Ctrl (ch);

	Set_cal_path_RBB (8); //Set control signals to path 8 (RX HighBand)

	Algorithm_B_RBB (); //Calibrate and Record the low frequency output amplitude (Algorithm B)

	Algorithm_F_RBB (RBB_37_0MHZ);// CalibrateByCap the output cuttoff frequency at 18,5 MHz MHz and store
	Algorithm_F_RBB (RBB_66_0MHZ);// CalibrateByCap the output cuttoff frequency at 33 MHz MHz and store
	Algorithm_F_RBB (RBB_108_0MHZ);// CalibrateByCap the output cuttoff frequency at 54 MHz MHz and store
}

// TBB

void Algorithms::Algorithm_A_TBB ()
{
	unsigned char RCAL_LPFLAD_TBB;

	RCAL_LPFLAD_TBB = 193; // default control value 193 - when 11MHz
	RCAL_LPFLAD_TBB = (unsigned char)(RCAL_LPFLAD_TBB * Resistor_calibration ()); // Multiply by ratio

	Modify_SPI_Reg_bits (0x0109, 7, 0, RCAL_LPFLAD_TBB);
	///TBB_RBANK = RCAL_LPFLAD_TBB; // Store RBANK Values (RCAL_LPFLAD_TBB) ???
	//Return the result of the multiplication. ????kam
}

unsigned short Algorithms::Algorithm_B_TBB ()
{
	//same algorith as rbb???
	return 0;
}

void Algorithms::Algorithm_C_TBB (unsigned char Band_id)
{
	unsigned short ADCOUT, LowFreqAmp;
	unsigned char CCAL_LPFLAD_TBB;

	Modify_SPI_Reg_bits (0x040A, 13, 12, 1); // AGC Mode = 1 (RSSI mode)

	Set_NCO_Freq (TBB_CalFreq[Band_id]); // 1 Apply a single tone frequency at “CalFreq”.

	CCAL_LPFLAD_TBB = 31;
	Modify_SPI_Reg_bits (0x010A, 12, 8, CCAL_LPFLAD_TBB); // 2 Set the “CCAL_LPFLAD_TBB” to maximum value.

	LowFreqAmp = Algorithm_B_RBB (); // Apply (Algorithm B).

	while (1)
	{
		Modify_SPI_Reg_bits (0x010A, 12, 8, CCAL_LPFLAD_TBB);

		ADCOUT = Get_SPI_Reg_bits(0x040B, 15, 0); //RSSI value // Measure the value of the amplitude at the ADC input. This value should be lower than “LowFreqAmp”.

		if (! (ADCOUT < LowFreqAmp)) break; //If amplitude is lower than “LowFreqAmp” repeat cycle
		if (CCAL_LPFLAD_TBB == 0) break;
		CCAL_LPFLAD_TBB--; // Decrease the control value “CCAL_LPFLAD_TBB” by one step.
	}

	TBB_CBANK[MIMO_ch] = CCAL_LPFLAD_TBB;
	// 6 Return the value of “CCAL_LPFLAD_TBB” as the calibrated CBANK value of TBB.
}

void Algorithms::Algorithm_D_TBB (unsigned char Band_id)
{
	unsigned short ADCOUT;

	Set_NCO_Freq (TBB_CalFreq[Band_id]); // 1 Apply a single tone at frequency equal to “CalFreq”

	Modify_SPI_Reg_bits (0x040A, 13, 12, 1); // AGC Mode = 1 (RSSI mode)

	ADCOUT = Get_SPI_Reg_bits(0x040B, 15, 0); //RSSI value
	if (ADCOUT > LowFreqAmp) // Compare the amplitude at the input  ADC to “LowFreqAmp”
	{
	}

	// 2 Compare the amplitude at the input  ADC to “LowFreqAmp”. If greater, then the pre-emphasis zero is faster than the real pole. And Vise-Versa. Decrease or increase respectively the zero frequency by one step.
	// 3 If the last step was in the opposite direction of the current step, then you have reached the optimal value of the pre-emphasis parameters. (the last step you increased by one step and this step you decreased, or, the last step you decreased and this step you increased). If not, then go back to step 2.
	// 4 Return the pre-emphasis zero setting.
}

void Algorithms::Algorithm_E_TBB (unsigned char Band_id)
{
	unsigned short ADCOUT;
	unsigned short LowFreqAmp;
	unsigned char low_band, CONTROL;

	Set_NCO_Freq (TBB_CalFreq[Band_id]); // Set CalFreq

	Modify_SPI_Reg_bits (0x040A, 13, 12, 1); // AGC Mode = 1 (RSSI mode)

	if(Band_id <= TBB_11_0MHZ) //If(“CalFreq”) <=11MHz, then CONTROL=RCAL_LPFLAD_TBB, else, CONTROL=RCAL_LPFH_TBB
	{
		low_band = 1; // CONTROL=RCAL_LPFLAD_TBB
	}
	else
	{
		low_band = 0; // CONTROL=RCAL_LPFH_TBB
	}

	CONTROL = 0; // Set the CONTROL to zero. This should bring the output cutt-off frequency to minimum.

	if (low_band) Modify_SPI_Reg_bits (0x0109, 7, 0, CONTROL); // write to RCAL_LPFLAD_TBB
		else Modify_SPI_Reg_bits (0x0109, 15, 8, CONTROL); // write to RCAL_LPFH_TBB

	LowFreqAmp = Algorithm_B_TBB (); // Apply (Algorithm B).
	Set_NCO_Freq (TBB_CalFreq[Band_id]); // Apply a single tone frequency at “CalFreq”.

	while (1)
	{
		if (low_band) Modify_SPI_Reg_bits (0x0117, 10, 0, CONTROL); // write to C_CTL_LPFL_RBB
			else Modify_SPI_Reg_bits (0x0116, 7, 0, CONTROL); // write to C_CTL_LPFH_RBB

		ADCOUT = Get_SPI_Reg_bits(0x040B, 15, 0); //RSSI value // Measure the value of the amplitude at the ADC input. This value should be lower than “LowFreqAmp”.

		if (! (ADCOUT < LowFreqAmp)) break; //If it is lower than “LowFreqAmp” repeat cycle
		if (CONTROL == 0xFF) break;
		CONTROL++; // Increase the CONTROL value by one.
	}

	// 8 Return the value of CONTROL.
	TBB_RBANK[MIMO_ch][Band_id] = CONTROL; // Store RBANK Values
}

void Algorithms::Set_cal_path_TBB (unsigned char path_no)
{
	switch (path_no)
	{
		case 1: // Current Amplifier Low Section Verification.
			break;

		case 2: // Current Amplifier High Section testing.
			break;

		case 3: // TX LPFLADDER Low Section testing.
			break;

		case 4: // TX REALPOLE Low Section testing
			break;

		case 5: // TX Lowband testing
			break;

		case 6: // TX BIQUAD High Section testing
			Modify_SPI_Reg_bits (0x010A, 15, 14, 0); // TSTIN_TBB == 0
			Modify_SPI_Reg_bits (0x0105, 4, 4, 0); // PD_LPFH_TBB == 0
			Modify_SPI_Reg_bits (0x0105, 14, 12, 3); // LOOPB_TBB<1:0> == 3
			Modify_SPI_Reg_bits (0x0105, 1, 1, 1); // PD_LPFS5_TBB == 1
			Modify_SPI_Reg_bits (0x0105, 2, 2, 1); // PD_LPFLAD_TBB == 1
			Modify_SPI_Reg_bits (0x010A, 13, 13, 0); // BYPLADDER_TBB == 0 (Digital Pre-Emphasis = “OFF”)
			break;
	}

	//RBB Control Bits
	Modify_SPI_Reg_bits (0x0118, 15, 13, 3); // INPUT_CTL_PGA_RBB == 3
	Modify_SPI_Reg_bits (0x0115, 2, 2, 1); // PD_LPFL_RBB == 1
	Modify_SPI_Reg_bits (0x0115, 3, 3, 1); // PD_LPFH_RBB == 1
	Modify_SPI_Reg_bits (0x010C, 1, 1, 1); // PD_TIA_RFE == 1
	Modify_SPI_Reg_bits (0x0119, 15, 15, 0); // OSW_PGA_RBB ==0
}

void Algorithms::Calibration_LowBand_TBB (unsigned char ch)
{
	MIMO_Ctrl (ch);
#warning Not finished!!!
	//not finished!!!!
}

void Algorithms::Calibration_HighBand_TBB (unsigned char ch)
{
	MIMO_Ctrl (ch);

	Set_cal_path_TBB (6); // Set control signals to path 6

	Algorithm_E_TBB (TBB_18_5MHZ);// CalibrateByRes the output cutoff frequency (Algorithm E)
	Algorithm_E_TBB (TBB_38_0MHZ);// CalibrateByRes the output cutoff frequency (Algorithm E)
	Algorithm_E_TBB (TBB_54_0MHZ);// CalibrateByRes the output cutoff frequency (Algorithm E)
}
