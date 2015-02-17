//==============================================================================
// File name:	 NumeralSystem.h
// ----------
//
// Description:	 CLASS for representing numbers in different Numeral systems.
// ------------	 
//
// How to use:	 When creating the class specify the desired numeral system. 
// -----------	 Than call ConvertNumber() with the number that is to be converted 
//            	 The result is returned in strConvertedNumber[32]- each of its 
//            	 elements holds a digit. The smallest digit is at strConvertedNumber[0].     	 
//            	 
//==============================================================================
#pragma once
#include "basedef.h"
#include <iostream>
using namespace std;



class NumeralSystem
{
private:

    U32    u32Base; //Will hold the number of the numeral system
   

public:
    NumeralSystem(U32 uNumeralSystem);
   
    //--Returns the base of the numeral system--//
    U32 WhichNumeralSystem(void);

    //--Convert the supplied number from base 10 to the one that the class is configured--//
    void ConvertNumber(U32 uNumberToConvert, U32 strConvertedNumber[32]);
};
