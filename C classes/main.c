#include <stdio.h>
#include <stdlib.h>
/// you can't make Classes in c
typedef struct vector {
	int* heap_array;
	int size;
} vector;//constructors

vector* construct1(int size, int arr[]) {
	vector* newthing = (vector*)malloc(1*sizeof(vector));
	newthing->heap_array = (int*)malloc(size * sizeof(int));
	for (int x = 0; x < size; x++) {
		newthing->heap_array[x] = arr[x];
	}
	newthing->size = size;
	return newthing;
};
void deconstruct(vector* vec) {
	free(vec->heap_array);
	free(vec);



};


void pushback(vector* vec, int value) {
	vec->heap_array = (int*)realloc(vec->heap_array, (vec->size + 1) * sizeof(int));
	vec->heap_array[vec->size] = value;
	vec->size++;
}


int main(void) {
	vector* my_vector;


	int arr[] = { 1,2,3,4 };//not really a good vector

	my_vector = construct1(4, arr);
	pushback(my_vector, 5);
	printf("%i", my_vector->heap_array[3]);
	printf("%i", my_vector->heap_array[4]);
	deconstruct(my_vector);
};