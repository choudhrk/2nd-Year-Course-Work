#include <stdio.h>
#include <stdlib.h>
#include "a4.h"
//Code developed by Abdulrab Mohammed

// https://stackoverflow.com/questions/2693631/read-ppm-file-and-store-it-in-an-array-coded-with-c
// used the above link for reference
PPM_IMAGE *read_ppm (const char *filename)
{
  char dummy;
  int red, green, blue;
  FILE *fp = fopen(filename, "r");
  if (fp == NULL)
  {
    fprintf(stderr, "cannot open file %s\n",filename);
  }
  PPM_IMAGE *img = (PPM_IMAGE *)malloc(sizeof(PPM_IMAGE));
  fscanf(fp, "%s", &dummy);
  fscanf(fp, "%d %d", &img->width, &img->height);
  fscanf(fp, "%d", &img->max_color);
  int i;




  PIXEL *data = (PIXEL *)malloc(sizeof(PIXEL)*img->width*img->height);

  img->data = data;
  for (i = 0; i < img->width*img->height; i++)
  {
    fscanf(fp, "%d %d %d ", &red, &green, &blue);
    // printf("%d %d %d", red, green, blue);
    img->data[i].r = red;
    img->data[i].g = green;
    img->data[i].b = blue;
    //printf("%d %d %d ", img->data[i].r, img->data[i].g, img->data[i].b);
  }
  fclose(fp);
  return img;
}


 void write_ppm(const char *filename, PPM_IMAGE *image)
 {
   FILE *fp = fopen(filename, "w");
   if (fp == NULL)
   {
     fprintf(stderr, "cannot open file %s\n",filename);
   }


   fprintf(fp, "P3\n");
   fprintf(fp, "%d %d\n", image->width, image->height);
   fprintf(fp, "%d\n", image->max_color);

   int i;
   for (i = 0; i < image->width * image->height; i++)
   {
     fprintf(fp, "%d %d %d ", image->data[i].r, image->data[i].g, image->data[i].b);
   }

 }
