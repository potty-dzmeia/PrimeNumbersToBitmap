//==============================================================================
// File name:	BitmapCreator.cpp
//
// Description:	Cpp file for BitmapCreator class  
//==============================================================================
#include "BitmapCreator.h"




//==============================================================================
// DESCRIPTION:         Initialization of the BitmapCreator class.
//                      The user must supply the correct values in order the 
//                      class to function properly.
//
// PARAMETERS:          u16BitCount - allowed values are:
//                           1 - for 1 bit per pixel (B&W bitmap)
//                           8 - for 8 bit per pixel (gray scale bitmap)
//
//                      s32Width    - Width in pixels. 
//                      s32Height   - Height in pixels.
//
// RETURN VALUE:        none
//
// DESIGN INFORMATION:  
//==============================================================================
BitmapCreator::BitmapCreator( 
                             U16     u16BitsPerPixel,
                             S32     s32Width,
                             S32     s32Height,
                             const wchar_t *fileName
                             )
{
    
    //Make sure the right bit mode is selected
    ASSERT( u16BitsPerPixel==1 || u16BitsPerPixel==8);


    //Fill the RGBQuad structure depending on color mode
    if( u16BitsPerPixel==1 ) //1bit mode
    {    
            //Make the first entry of the table be white color
        bmpRGBQuad[0].rgbBlue = (U8) 255;
        bmpRGBQuad[0].rgbGreen= (U8) 255;
        bmpRGBQuad[0].rgbRed  = (U8) 255;
        bmpRGBQuad[0].rgbReserved = 0;
            //Make the second entry in the table be black color
        bmpRGBQuad[1].rgbBlue = (U8) 0;
        bmpRGBQuad[1].rgbGreen= (U8) 0;
        bmpRGBQuad[1].rgbRed  = (U8) 0;
        bmpRGBQuad[1].rgbReserved = 0;
    }
    else //8bit mode
    {
        //Set the gray scale palette if in 8bit mode
        for(unsigned i = 0; i < 256; i++)
        {
            bmpRGBQuad[i].rgbBlue = (U8) i;
            bmpRGBQuad[i].rgbGreen= (U8) i;
            bmpRGBQuad[i].rgbRed  = (U8) i;
            bmpRGBQuad[i].rgbReserved = 0;
        }
    }
         
  
    //Init FILEHEADER
    bmpFileHeader.bfType        = 0x4D42;   //Indicate .bpm file
    bmpFileHeader.bfReserved1   = 0; 
    bmpFileHeader.bfReserved2   = 0;
    bmpFileHeader.bfOffBits     = sizeof(bmpFileHeader) + sizeof(bmpRGBQuad)+ sizeof(bmpInfoHeader); //Where the bitmap data starts
        //calculate the expected size of the image
    bmpFileHeader.bfSize        = bmpFileHeader.bfOffBits + (s32Width*s32Height*u16BitsPerPixel)/8;

    //Init INFOHEADER
    bmpInfoHeader.biSize        = sizeof (bmpInfoHeader);					                                      
    bmpInfoHeader.biPlanes      = 1; //always 1
    bmpInfoHeader.biCompression = 0; //No comporession
    bmpInfoHeader.biSizeImage   = 0; //(s32Width*s32Height*u16BitsPerPixel)/8; //This may be set to zero for BI_RGB bitmaps.
    bmpInfoHeader.biClrUsed     = 0; //Use the information from biBitCount
    bmpInfoHeader.biClrImportant= 0; //All colors are important
    bmpInfoHeader.biXPelsPerMeter = 0; //
    bmpInfoHeader.biYPelsPerMeter = 0; //

    bmpInfoHeader.biBitCount    = u16BitsPerPixel;  //Set the color mode
    bmpInfoHeader.biWidth       = s32Width;         //Set width in pixels
    bmpInfoHeader.biHeight      = -s32Height;       //(-)Indicates top to bottom bitmap(not inverted)

     
        //Open the file where the values will be written
    bmpFileHandle.open(fileName, ios::out | ios::binary | ios::trunc);
    
        //Write the headers into the bitmap file
    bmpFileHandle.write( (char*) &bmpFileHeader, sizeof(bmpFileHeader) );
    bmpFileHandle.write( (char*) &bmpInfoHeader, sizeof(bmpInfoHeader) );
    bmpFileHandle.write( (char*) &bmpRGBQuad, sizeof(bmpRGBQuad) );
}   




BitmapCreator::~BitmapCreator(void)
{
        //Close the file
    if( bmpFileHandle.is_open() )
    {
        bmpFileHandle.close();
    }
}


//==============================================================================
// DESCRIPTION:         Writes a byte into the bitmap file.
//
// PARAMETERS:          u8Input - the byte that will be written.
//                         -when in B&W the bits of the input byte are represented
//                          on the bitmap image. 0 bit for white and 1bit for black.
//                         -when in 8bit mode the input byte is represented with 
//                          gray color 0 being black and 255 being white.
//
// RETURN VALUE:        true - if the write operation was successful
//                      false- if the write operation was unseccessful
//
// DESIGN INFORMATION:  
//==============================================================================
bool BitmapCreator :: WriteByte(U8 u8Input)
 {
        //If the file was not open return false
     if( !bmpFileHandle.is_open() )
         return false;

        //write the byte value
     bmpFileHandle.put(u8Input);

     return true;
 }
