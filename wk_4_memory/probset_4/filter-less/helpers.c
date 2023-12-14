#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // finding average of the all colors to add grayscale
            float avg_gray = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / (float)3.0 ;

            image[i][j].rgbtRed = round(avg_gray);
            image[i][j].rgbtGreen = round(avg_gray);
            image[i][j].rgbtBlue = round(avg_gray);
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepia_red = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue); //red_sepia
            int sepia_green = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue); //green_sepia
            int sepia_blue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue); //blue_sepia

            // assinginging max sepia values if any sepia colour crosses value of 255
            if (sepia_red > 255)
            {
                sepia_red = 255;
            }
            if (sepia_green > 255)
            {
                sepia_green = 255;
            }
            if (sepia_blue > 255)
            {
                sepia_blue = 255;
            }

            image[i][j].rgbtRed = sepia_red;
            image[i][j].rgbtGreen = sepia_green;
            image[i][j].rgbtBlue = sepia_blue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp; // creating a temprory variable to store pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)]; //assigning pixel to its complementory pixel
            image[i][width - (j + 1)] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width]; //creatinf temperory variable to store the values of a particular pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int blur_red = 0;
            int blur_green = 0;
            int blur_blue = 0;
            float pixels = 0;

            // finding average color value for pixel by finding average of pixels surrounding it
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    int row = i + k;
                    int col = j + l;

                    if (row >= 0 && row < height && col >= 0 && col < width)
                    {
                        blur_red += temp[i + k][j + l].rgbtRed;
                        blur_green += temp[i + k][j + l].rgbtGreen;
                        blur_blue += temp[i + k][j + l].rgbtBlue;
                        pixels++;
                    }
                    else
                    {
                        continue;
                    }
                }
            }

            image[i][j].rgbtRed = round(blur_red / pixels);
            image[i][j].rgbtGreen = round(blur_green / pixels);
            image[i][j].rgbtBlue = round(blur_blue / pixels);
        }
    }
}
