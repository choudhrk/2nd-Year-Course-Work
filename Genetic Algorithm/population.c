#include <stdio.h>
#include <stdlib.h>
#include "a4.h"
PIXEL *generate_random_image(int width , int height , int max_color);
Individual *generate_population (int population_size, int width, int height , int max_color);

Individual *generate_population(int population_size, int width, int height , int max_color){
	int i = 0;//Initializing the iterator.
	Individual *Population = malloc(sizeof(Individual)*population_size);//Allocating memory to the array of Individuals.
	//Below loop assigns every 'Individual' a width, height, max_color, and an array of PIXELS called data.
	while(i < population_size){
		Population[i].image.width = width; 
		Population[i].image.height = height;
		Population[i].image.max_color = max_color;
		Population[i].image.data = generate_random_image(width, height, max_color);
		i++;
	}
	//Returns population array.
	return Population;
}
PIXEL *generate_random_image(int width , int height , int max_color){
	int i = 0, size = height*width; //Initializing counter and size of PIXEL array.
	PIXEL *PixArr = malloc(sizeof(PIXEL)*size);//Allocating memory to the array of PIXELS.
	//Below loop assigns every PIXEL a random RGB value.
	while(i < size){
		PixArr[i].r = rand()%max_color; 
		PixArr[i].g = rand()%max_color; 
		PixArr[i].b = rand()%max_color;
		i++;	
	}
	//Returns array of  PIXELS.
	return PixArr;
}