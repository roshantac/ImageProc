#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 256
#define WIDTH 256
int main()
{
    FILE *fp, *outfp ;
    fp=fopen("image.raw","rb");
    outfp = fopen("ImageOut.raw", "wb");
    int i,j;
    unsigned char imageBuff[HEIGHT][WIDTH];
    if(fp == NULL)
    {
        printf("\n Error in Opening File \n");
    }
    else
    {
        for(i=0;i<HEIGHT;i++)
            fread(imageBuff[i], 1, WIDTH, fp );
       for(i=0;i<HEIGHT;i++)
        for(int j=0;j<WIDTH;j++)
            if(imageBuff[i][j]>127)
                imageBuff[i][j] =255;
            else
                imageBuff[i][j] = 0;


        fwrite( imageBuff, 1, WIDTH*HEIGHT, outfp );
    }
    fclose(fp);
    return 0;
}
