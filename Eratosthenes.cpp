//==============================================================================
// File name:	Eratosthenes.cpp
//
// Description:	Cpp file for Eratosthenes class  
//==============================================================================
#include "eratosthenes.h"


Eratosthenes::Eratosthenes(void)
{
    //Set the pointer to NULL
    puSieve = NULL;

    //Reset the variable
    u32NumberOfPrimes = 0;
    
}

Eratosthenes::~Eratosthenes(void)
{
	if( puSieve != NULL)
		delete(puSieve);
}


//==============================================================================
// DESCRIPTION:         Function that generates primes up to the desired number   
//
// PARAMETERS:          u32UpToNumber - the highest number that will be tested for
//                                    primality
//
// RETURN VALUE:        TRUE    - success
//                      FALSE   - error
//
// DESIGN INFORMATION: 
//==============================================================================
bool Eratosthenes :: GeneratePrimes(IN_PARAM U32 u32UpToNumber)
{

        //If memory was allocated before that - free it
    if( puSieve != NULL )
        delete(puSieve);

        //Check for too large number
    if( (u32UpToNumber < 2) || (u32UpToNumber > 1000000)  )
    {
        cout<<"The supplied argument must be greater than 1 and smaller than 10 000 000"<<endl;
        return 0;
    }
       
        //Save the size of the array
    u32MaxNumber = u32UpToNumber+1;
        //Allocate memory for the sieve
    puSieve = new unsigned int[u32MaxNumber];

    if( puSieve == NULL )
    {
        cout<<endl<<"Error allocating memory for the sieve"<<endl;
        return 0;
    }
         //Set the buffer to all 0s
    memset( (void*)puSieve, 0, sizeof(unsigned int) * u32MaxNumber );


        //0 and 1 are not primes
    puSieve[0] = 1;
    puSieve[1] = 1;

        //Start filling the sieve
    for(unsigned N = 3; N < sqrt(double(u32MaxNumber)) ; N +=2 ) //For every number up to sqtr(N) start checking out the divisibles
    {
   
        for(int i = 2;  ((N*i) < u32MaxNumber) ;  i++)
        {
            puSieve[N*i] = 1;   //set 1 to the numbers that are not prime
        }

    }
    
    //Set the starting point for GetNextPrimeNumber()
    u32CurrentPrime = 1;
        
    return 1;
}

//==============================================================================
// DESCRIPTION:         Function that gives in succession prime numbers   
//
// PARAMETERS:          uNextPrime  - pointer to variable to hold the prime number
//
// RETURN VALUE:        true    - The returned number is prime 
//                      false   - No more primes left
//
// DESIGN INFORMATION: 
//==============================================================================
bool Eratosthenes :: GetNextPrimeNumber(OUT_PARAM U32 *uNextPrime)
{  
       
        //If in the beginning return the number 2 as prime
    if(u32CurrentPrime == 1)
    {
        *uNextPrime     = 2; 
        u32CurrentPrime   = 3;
        return true;
    }
        
        //Search for the next prime
    for(U32 i = u32CurrentPrime; i < u32MaxNumber; i+=2)
    {
        if( puSieve[i] == 0 )
        {
                //Return the prime number
            *uNextPrime     = i;  
            u32CurrentPrime   = i+2;
                //Indicate that prime was found
            return true;
        }
    }//for

        //Indicate that prime was NOT found  
    return false;
}



//==============================================================================
// DESCRIPTION:         Function that makes GetNextPrimeNumber() to return primes
//                      starting again from 2.                    
//
// PARAMETERS:          
//
// RETURN VALUE:       
//
// DESIGN INFORMATION: 
//==============================================================================
void Eratosthenes :: Reset(void)
{
    u32CurrentPrime = 1; 
}   


//==============================================================================
// DESCRIPTION:         Function that prints the sieve   
//
// PARAMETERS:         
//
// RETURN VALUE:        
//
// DESIGN INFORMATION: 
//==============================================================================
 void Eratosthenes :: PrintTheSeive(void)
 {
     cout<<"Printing the sieve: "<<endl;

     for(U32 i= 0; i < u32MaxNumber; i++)
     {
         cout<< puSieve[i]<< endl;
     }
 }



 //==============================================================================
// DESCRIPTION:         Returns how many prime numbers were found  
//
// PARAMETERS:         
//
// RETURN VALUE:        U32 - the count of the prime numbers
//
// DESIGN INFORMATION: 
//==============================================================================
 U32 Eratosthenes :: GetNumberOfPrimes()
 {
    
     //check if the current number is prime and count it
     u32NumberOfPrimes++; //Count once for number 2
     for(U32 i = 3; i < u32MaxNumber; i+=2)
         if(puSieve[i] == 0)//if prime number count it
            u32NumberOfPrimes++;

     return u32NumberOfPrimes;
 }