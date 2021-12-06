#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;
            int avg = round(((float) red + (float) blue + (float) green) / 3);
            image[i][j].rgbtRed = image[i][j].rgbtBlue = image[i] [j].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int ob = image[i][j].rgbtBlue;
            int og = image[i][j].rgbtGreen;
            int ore = image[i][j].rgbtRed;
            int sred, sgre, sblu;
            sred = round(.393 * ore + .769 * og + .189 * ob);
            if (sred > 255)
            {
                sred = 255;
            }
            sgre = round(.349 * ore + .686 * og + .168 * ob);
            if (sgre > 255)
            {
                sgre = 255;
            }
            sblu = round(.272 * ore + .534 * og + .131 * ob);
            if (sblu > 255)
            {
                sblu = 255;
            }
            image[i][j].rgbtBlue = sblu;
            image[i][j].rgbtGreen = sgre;
            image[i][j].rgbtRed = sred;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumred = 0;
            int sumblue = 0;
            int sumgreen = 0;
            float count = 0;
            for (int ii = i - 1; ii < i + 2; ii++)
            {
                if (ii < 0 || ii >= height)
                {
                    continue;
                }
                for (int jj = j - 1; jj < j + 2; jj++)
                {
                    if (jj < 0 || jj >= width)
                    {
                        continue;
                    }
                    sumred += image[ii][jj].rgbtRed;
                    sumblue += image[ii][jj].rgbtBlue;
                    sumgreen += image[ii][jj].rgbtGreen;
                    count++;
                }
            }
            temp[i][j].rgbtRed = round(sumred / count);
            temp[i][j].rgbtBlue = round(sumblue / count);
            temp[i][j].rgbtGreen = round(sumgreen / count);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
        }
    }
    return;
}
