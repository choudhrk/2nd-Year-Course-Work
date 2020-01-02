#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "a4.h"
//Code developed by Abdulrab Mohammed

double comp_distance (const PIXEL *A, const PIXEL *B, int image_size)
{
  double sum = 0;
  int i = 0;
  // image_size can = width*height
  // image_size = img->width*img-height
  for (i = 0; i < image_size; i++)
  {
    sum += ((A[i].r - B[i].r)*(A[i].r - B[i].r) + (A[i].g - B[i].g)*(A[i].g - B[i].g) + (A[i].b - B[i].b)*(A[i].b - B[i].b));

  }
  double fsumAB = sqrt(sum);
  return fsumAB;
}

void comp_fitness_population(const PIXEL *image, Individual *individual, int population_size)
{
  for(int i = 0; i < population_size; i++)
  {
    individual[i].fitness = comp_distance(image, individual[i].image.data, (individual[i].image.width*individual[i].image.height));
  }
}

