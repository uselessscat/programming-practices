#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE value = round(((float)image[i][j].rgbtRed + (float)image[i][j].rgbtGreen + (float)image[i][j].rgbtBlue) / 3.0);

            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = value;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // swap struct values, as i understand do a deep copy
            RGBTRIPLE aux = image[i][j];

            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = aux;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*image_copy)[width] = calloc(height, width * sizeof(RGBTRIPLE));

    // copy image, to get original values
    memcpy(image_copy, image, height * width * sizeof(RGBTRIPLE));

    int bsize = 1;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sum_red = 0.0, sum_green = 0.0, sum_blue = 0.0;
            int count = 0;
            int x_start = i - bsize, x_end = i + bsize, y_start = j - bsize, y_end = j + bsize;

            // >:c
            // https://stackoverflow.com/questions/3437404/min-and-max-in-c
            // check bounds
            if (x_start < 0)
            {
                x_start = 0;
            }

            if (x_end >= height)
            {
                x_end = height - 1;
            }

            if (y_start < 0)
            {
                y_start = 0;
            }

            if (y_end >= width)
            {
                y_end = width - 1;
            }

            for (int k = x_start; k <= x_end; k++)
            {
                for (int m = y_start; m <= y_end; m++)
                {
                    count++;
                    sum_red += image_copy[k][m].rgbtRed;
                    sum_green += image_copy[k][m].rgbtGreen;
                    sum_blue += image_copy[k][m].rgbtBlue;
                }
            }

            image[i][j].rgbtRed = round(sum_red / count);
            image[i][j].rgbtGreen = round(sum_green / count);
            image[i][j].rgbtBlue = round(sum_blue / count);
        }
    }

    free(image_copy);

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*image_copy)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    memcpy(image_copy, image, height * width * sizeof(RGBTRIPLE));

    int G[3][3] =
    {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sum_redx = 0.0, sum_greenx = 0.0, sum_bluex = 0.0;
            float sum_redy = 0.0, sum_greeny = 0.0, sum_bluey = 0.0;
            int x_start = 0, x_end = 2, y_start = 0, y_end = 2;

            if (i - 1 < 0)
            {
                x_start = 1;
            }

            if (i + 1 >= height)
            {
                x_end = 1;
            }

            if (j - 1 < 0)
            {
                y_start = 1;
            }

            if (j + 1 >= width)
            {
                y_end = 1;
            }

            for (int k = x_start; k <= x_end; k++)
            {
                for (int m = y_start; m <= y_end; m++)
                {
                    int x = i + k - 1, y = j + m - 1;

                    sum_redx += image_copy[x][y].rgbtRed * G[k][m];
                    sum_greenx += image_copy[x][y].rgbtGreen * G[k][m];
                    sum_bluex += image_copy[x][y].rgbtBlue * G[k][m];

                    sum_redy += image_copy[x][y].rgbtRed * G[m][k];
                    sum_greeny += image_copy[x][y].rgbtGreen * G[m][k];
                    sum_bluey += image_copy[x][y].rgbtBlue * G[m][k];
                }
            }

            int r = (int) round(sqrt(sum_redx * sum_redx + sum_redy * sum_redy));
            int g = (int) round(sqrt(sum_greenx * sum_greenx + sum_greeny * sum_greeny));
            int b = (int) round(sqrt(sum_bluex * sum_bluex + sum_bluey * sum_bluey));

            if (r > 255)
            {
                r = 255;
            }

            if (g > 255)
            {
                g = 255;
            }

            if (b > 255)
            {
                b = 255;
            }

            image[i][j].rgbtRed = r;
            image[i][j].rgbtGreen = g;
            image[i][j].rgbtBlue = b;
        }
    }

    free(image_copy);
    return;
}
