#ifndef VECTOR_H
#define VECTOR_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Vector_ {
	unsigned int size;
	unsigned int amount;
	int *array;
} Vector;

Vector CreateVector(unsigned int size, int fill, int values) {
	Vector new_vector;
	new_vector.size = size;
	new_vector.array = malloc(size * sizeof(new_vector.array));
	
	for (unsigned int i = 0; i < size; ++i) {
		new_vector.array[i] = values;
	}
	
	switch (fill){
		case 1:
			new_vector.amount = size;
			break;
		case 0:
			new_vector.amount = 0;
			break;
	}
	
	return new_vector;
}

void AppendToVector(Vector *the_vector, int item) {
	if (the_vector->amount + 1 > the_vector->size) {
		unsigned int new_size = the_vector->size * 2;
		int *new_array;
		new_array = malloc(new_size * sizeof(new_array));
		for (unsigned int i = 0; i < the_vector->size; ++i){
			new_array[i] = the_vector->array[i];
		}
		free(the_vector->array);
		the_vector->array = new_array;
		the_vector->size = new_size;
	}
	the_vector->array[the_vector->amount] = item;
	++the_vector->amount;
}

void DeleteVector(Vector *vector_to_be_deleted){
	free(vector_to_be_deleted->array);
}
#endif