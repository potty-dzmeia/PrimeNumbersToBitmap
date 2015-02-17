//==============================================================================
// File name:	numeralsystem.cpp
//
// Description:	Cpp file for NumeralSystem class
//==============================================================================
#include "numeralsystem.h"

NumeralSystem :: NumeralSystem(U32 uNumeralSystem)
{
    u32Base = uNumeralSystem;
}


//==============================================================================
// DESCRIPTION:         Returns the base of the numeral system   
//
// PARAMETERS:          void
//
// RETURN VALUE:        unsigned - The current base system that the class is 
//                                 working with.
//
// DESIGN INFORMATION: 
//==============================================================================
U32 NumeralSystem :: WhichNumeralSystem(void)
{

    return u32Base;
}


//==============================================================================
// DESCRIPTION:         Convert the supplied number from base 10 to the one that 
//                      the class is configured.
//                       
// PARAMETERS:          uNumberToConvert - the number that must be convert to 
//                              another numeral system
//                      strConvertedNumber - Array that holds each of the
//                              digits forming the number. Must be 32 digits long
//                              because of the binary representation.
//
// RETURN VALUE:       
//
//
// DESIGN INFORMATION: 
//==============================================================================
void NumeralSystem :: ConvertNumber(IN_PARAM  U32 uNumberToConvert,
                                    OUT_PARAM U32 strConvertedNumber[32])
{
    U32 uTemp;
    U32 uCounter = 0;
     

    //Reset the input array to all 0s
    memset((void*)strConvertedNumber, 0, sizeof(U32)*32);


    while(uNumberToConvert) 
    {       //Find the reminder and ...
       uTemp = uNumberToConvert%u32Base;
            //fill the structure with the successive digit. 
       strConvertedNumber[uCounter++] = uTemp;  
            //
       uNumberToConvert /= u32Base;
    }
   
}