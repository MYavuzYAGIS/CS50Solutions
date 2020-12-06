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
    return;
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
