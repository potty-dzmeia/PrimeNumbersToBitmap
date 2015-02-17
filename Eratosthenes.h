//==============================================================================
// File name:	 Eratosthenes.h
// ----------
//
// Description:	 The class Eratosthenes finds prime numbers using the Eratosthenes
// ------------	 methode.
//
// How to use:	 First call GeneratePrimes() with the desired input parameter.
// -----------	 Then call GetNextPrimeNumber() which returns 
//            	 prime numbers starting from 2.
//            	 When no more primes are left GetNextPrimeNumber()  
//            	 returns 0.
//            	 To read again the prime numbers call ResetNextPrimeNumber()
//            	 than continue calling GetNextPrimeNumber().
//==============================================================================
#pragma once
#include <complex>
#include <iostream>
#include "basedef.h"
using namespace std;





class Eratosthenes
{
private:
    U32    u32MaxNumber;     //Maximal possible size of the prime number
    U32    u32CurrentPrime;  //The current prime to be returned from GetNextPrimeNumber();
    U32    u32NumberOfPrimes;//How many prime numbers were found
public:
    unsigned int    *puSieve; //pointer to the Sieve of Eratosthenes


public:
    Eratosthenes(void);
    ~Eratosthenes(void);
    

    //--Function that generates primes up to the desired number--//
    bool GeneratePrimes(U32 u32UpToNumber);

    //--Function that gives in succession prime numbers--//
    bool GetNextPrimeNumber(OUT_PARAM U32 *uNextPrime);

    //--Function that forces GetNextPrimeNumber() to start again from 2--//
    void Reset(void);

    //--Function that gives in succession prime numbers--//
    void PrintTheSeive(void);

    //--Shows how many primes were found--//
    U32 GetNumberOfPrimes();
};
