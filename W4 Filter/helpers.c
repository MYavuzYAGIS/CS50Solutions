#include "helpers.h"
#include <math.h>

// image is a 2D array where Dimensions are height and width. the image is height rows long and witdh columns wide. Width is array within height.

// We have to make sure that the RGB does not overflow!


int NoFlow(int RGB){
    if(RGB> 255){
        RGB=255;
    }
    return RGB;
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average;
        // so since all the gray tones are RGBs that are close to each other, I took the mean value and reassigned to each channel of colors.
    for(int i = 0; i < width; i++ ){
        for(int j =0; j<height;j++){
            average = round((image[j][i].rgbtBlue + image[j][i].rgbtGreen +image[j][i].rgbtRed)/3.00);
            image[j][i].rgbtBlue = average;
            image[j][i].rgbtGreen = average;
            image[j][i].rgbtRed = average;
        }
    }
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
      // lets introduce the new values
        int sBlue; 
        int sRed;
        int sGreen;

        for(int i=0; i<width; i++){
            for(int j=0; j<height; j++){
                sBlue = NoFlow(round(0.272 * image[j][i].rgbtRed + 0.534 * image[j][i].rgbtGreen + 0.131*image[j][i].rgbtBlue));
                sGreen = NoFlow(round(0.349 * image[j][i].rgbtRed + 0.686 * image[j][i].rgbtGreen + 0.168*image[j][i].rgbtBlue));
                sRed = NoFlow(round(0.393 * image[j][i].rgbtRed + 0.769 * image[j][i].rgbtGreen + 0.189*image[j][i].rgbtBlue));

                image[j][i].rgbtBlue = sBlue;
                image[j][i].rgbtGreen = sGreen;
                image[j][i].rgbtRed = sRed;

            }
        }        



}

// Reflect image horizontally
 void reflect(int height, int width, RGBTRIPLE image[height][width])
 {
     return;
 }

// Blur image
 void blur(int height, int width, RGBTRIPLE image[height][width])
 {
     return;
 }
