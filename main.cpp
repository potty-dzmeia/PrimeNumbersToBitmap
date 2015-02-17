#include <iostream>
#include "Eratosthenes.h"
#include "NumeralSystem.h"
#include "BitmapCreator.h"
using namespace std;


int main(void)
{
    U32           u32Temp;
    U32           u32Array[32];  
    BitmapCreator   *bmpCreator;

    //Generate prime numbers up to 1 000 000  
    Eratosthenes    Erato;
    Erato.GeneratePrimes(1000000);

 

    /*** 
        Create picture containing 20000 primes.      
        The represententaion of the numbers will be
        in binary numeral system
    ***/
    bmpCreator = new BitmapCreator( 1,      //8bit color
                                    32,     //32 pixels - pixel for each bit
                                    20000,  //Height in pixels
                                    L"PrimeBinary.bmp"//filename
                                   ); 
   
    for(int i = 0; i<20000; i++)
    {
       
        //Get a prime number
        Erato.GetNextPrimeNumber(&u32Temp);
        //Write the prime number to the bitmap image
            //Start writing with the most significant byte
        
        bmpCreator->WriteByte( u32Temp>>24 );           
        bmpCreator->WriteByte( u32Temp>>16 );    
        bmpCreator->WriteByte( u32Temp>>8  );    
        bmpCreator->WriteByte( u32Temp     );    
    }
    
    delete(bmpCreator);
  


    /*** 
        Create picture containing 20000 primes.      
        The represententaion of the numbers will be
        in numeral system of base 3.
        12 pixels will be enought to represent the largest prime(224737)
    ***/
    bmpCreator = new BitmapCreator ( 8,      //8bit color
                                     32,     //32 pixels - pixel for each digit
                                     20000,  //Height in pixels
                                     L"PrimeBaseThree.bmp"//filename
                                    ); 
    
    //confingure the converter class 
    NumeralSystem numSystem(3);
    //Start getting prime numbers from 2
    Erato.Reset();

    for(int i = 0; i<20000; i++)
    {
        //Get a prime number
        Erato.GetNextPrimeNumber(&u32Temp);
          
        //Convert the number to base 3
        numSystem.ConvertNumber(u32Temp, u32Array);

        //Write the prime number to the bitmap image
        for(int z = 0; z < 32; z++)
            bmpCreator->WriteByte( u32Array[z] * (255/2));        

    }

    delete(bmpCreator);

    
   
    
        
   
    return 0;
}