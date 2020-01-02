#include <stdio.h>
#include <stdlib.h>
#include "a4.h"

void mutate (Individual *individual , double rate);
void mutate_population(Individual *individual , int population_size , double rate);

void mutate_population(Individual *individual , int population_size , double rate){
	int i = population_size/4;
	while(i < population_size){
		mutate(individual+i , rate);
		i++;
	}
}
void mutate(Individual *individual , double rate){
	int height = individual->image.height, width = individual->image.width, max_color = individual->image.max_color;
	int size = height*width; int i = 0;
	int MutPix = (int) (size*rate/100); 
	while(i < MutPix){
		int RandPix = rand()%size;
		individual->image.data[RandPix].r = rand()%max_color;
		individual->image.data[RandPix].g = rand()%max_color;
		individual->image.data[RandPix].b = rand()%max_color;
		i++;
	}
}