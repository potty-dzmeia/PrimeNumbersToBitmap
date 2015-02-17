//==============================================================================
// File name:	 BitmapCreator.h
// ----------
//
// Description:	 Class for writing 8 bit values in a bitmap picture.
// ------------	 The bitmap file can be Black&White or 8bit gray scale. 
//               -When in B&W mode the individual bits of the byte are presented on
//               the bitmap image. Note that the bit ordering is most significant
//               bit first (down bit ordering).
//               -When in 8bit mode the byte is presented as a pixel.
//               If the byte has value 0 the pixel will be black and if the byte
//               has value 255 the pixel will be white. All the other values between
//               0 an 255 represents colors between black and white
//                       
// How to use:	 Create a class specifying the bit ordering and resolution
// -----------	 and than start writing bits to the file.
//            	    	     	 
//            	 
//==============================================================================
#pragma once
#include "basedef.h"    //typedefs for basic types
#include "MYASSERT.h"   //defines _Assert() function
#include <iostream>
using namespace std;




					  //Define the headfers for the bitmap file 
//------------------------------------------------------------------------------
//Define the bitmap headers if windows.h is not included
#ifndef _WINDOWS_

//Define the headers for the bitmap file
typedef struct tagBITMAPFILEHEADER
{ 

	U16		bfType;	// Specifies the file type.
					// Must be 0x4D42 for .BMP
	U32		bfSize;	 // Specifies the size in bytes of
					 // the bitmap file.
	U16		bfReserved1; 	// Reserved; must be zero.
	U16		bfReserved2; 	// Reserved; must be zero.
	U32		bfOffBits;	// Specifies the offset, in
						// bytes, from the
						// BITMAPFILEHEADER structure
						// to the bitmap bits.
} BITMAPFILEHEADER;




//define the bitmap info header structure
typedef struct tagBITMAPINFOHEADER{ 

	U32		biSize;	// Specifies the number of
					// bytes required by the structure.
	S32		biWidth;	// Specifies the width of the bitmap, in pixels.
	S32		biHeight;	// Specifies the height of the bitmap, in pixels.
						// If biHeight is positive, the bitmap is a
						// bottom-up DIB and its
						// origin is the lower left corner
						// If biHeight is negative, the bitmap
						// is a top-down DIB and its origin is the upper left corner.
	U16		biPlanes;  // Specifies the number of color planes, must be 1.
	U16		biBitCount; // Specifies the number of bits per pixel.
					   // This value must be 1, 4, 8, 16, 24, or 32.
	U32		biCompression; // specifies type of compression (advanced)
						   // it will always be
						   // BI_RGB for uncompressed .BMPs
						   // which is what we’re going to use
	U32     biSizeImage;		// size of image in bytes
	
    S32		biXPelsPerMeter;// specifies the number of pixels per meter in X-axis
	
    S32		biYPelsPerMeter;// specifies the number of pixels per meter in Y-axis
	
    U32     biClrUsed; // specifies the number of colors used by the bitmap
	
    U32     biClrImportant; // specifies the number of colors that are important

} BITMAPINFOHEADER;

//Define the structure to hold the palette
typedef struct tagRGBQUAD {
  U8    rgbBlue; 
  U8    rgbGreen; 
  U8    rgbRed; 
  U8    rgbReserved;    //not used must be 0
} RGBQUAD; 


#endif // ifndef _WINDOWS_





						//The BitmapCreator Class
//------------------------------------------------------------------------------
class BitmapCreator
{

private:
    fstream             bmpFileHandle;     //handle to opened file

	BITMAPFILEHEADER	bmpFileHeader;
	BITMAPINFOHEADER	bmpInfoHeader;
    RGBQUAD             bmpRGBQuad[256];


	

public:
	BitmapCreator(U16 u16BitsPerPixel, 
                  S32 s32WidthInPixels, 
                  S32 s32HeightInPixels, 
                  const wchar_t *fileName);

	~BitmapCreator(void);


public:

    //-----------------Writes a byte into the bitmap file------------------//
    bool WriteByte(U8 u8Input);
};
