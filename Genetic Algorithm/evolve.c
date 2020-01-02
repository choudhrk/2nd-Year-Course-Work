#include <stdio.h>
#include <stdlib.h>
#include "a4.h"
static int cmpfunc(const void * a, const void * b); //Comparison function used for qsort.
PPM_IMAGE *evolve_image(const PPM_IMAGE *image, int num_generations, int population_size , double rate);
void free_image ( PPM_IMAGE *p);

PPM_IMAGE *evolve_image(const PPM_IMAGE *image, int num_generations, int population_size , double rate){
	int i = 0;
	int width = image[0].width, height = image[0].height, max_color = image[0].max_color;
	Individual *Population = generate_population(population_size, width, height , max_color);//Generate poulation.
	comp_fitness_population(image->data, Population, population_size);//Implement fitness for all individuals;
	qsort(Population, population_size, sizeof(Individual), cmpfunc);//Sort based on fitness(use qsort from stdlib).
	//To get 10 diff files: //char *filenames[10] = {"me3.ppm","me4.ppm","me5.ppm","me6.ppm","me7.ppm","me8.ppm","me9.ppm","me10.ppm","me11.ppm","me12.ppm"}; 
	while(i < num_generations){
		crossover(Population, population_size);
		mutate_population(Population , population_size , rate);//Mutate resulting individual images.
		comp_fitness_population(image->data, Population, population_size);//Implement fitness for all individuals;//Compute fitness of mutated individual
		qsort(Population, population_size, sizeof(Individual), cmpfunc);//Sort based on fitness(use qsort from stdlib).
		//Tring to read into new files but gives incompatible type error. //write_ppm(filenames[i], Population[i].image);
		printf("%d: Fitness: %lf\n", i, Population[0].fitness);
		i++;
	}
	//For running the program this part is commented out as it doesnt let the image to be made. But to test on valgrind it is activated.
	/*int j = ((population_size)-1);
	while(j > 0){ //Freeing all Individuals except fittest one.
		free(&Population[j]);
		j--;
	}*/
	return &(Population[0].image); //Returns fittest image.
}
//Used to free one PPM_IMAGE struct.
void free_image(PPM_IMAGE *p){
	free(p->data);
	free(p);
}
//Below Function to be used in qsort.
static int cmpfunc(const void * a, const void * b){
   return (( *(Individual*)a).fitness - (*(Individual*)b).fitness );
}