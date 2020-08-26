#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>

typedef struct array_list {
    int size;
    int count;
    int* array;
} array_list;


array_list* new_array_list(int size) {
    array_list* output = (array_list*)calloc(size, sizeof(array_list));
    output->array = (int*)calloc(size, sizeof(int));
    output->count = 0;
    output->size = size - 1;
    return output;
}

void array_list_free(array_list* list) {
    free(list->array);
    free(list);
}

void array_list_add(array_list* list, int input) 
{
    if(list->count <= list->size){
	list->array[list->count] = input;
    } else {
	list->array = realloc(list->array, sizeof(int*) * list->size + 1);
	list->array[list->count] = input;
	list->size += 1;
    }

    list->count += 1;
    printf("Size: %i\n", list->size);
    printf("Count: %i\n", list->count);
    printf("Memory: %zu Bytes\n", sizeof(list->array) * sizeof(int) * list->size);
}

void array_list_remove(array_list* list, int index) 
{
    if(index >= list->size) {
	int* temp = (int*)calloc(list->size, sizeof(int));
	if(index == 0) {
	list->array = realloc(list->array, sizeof(int*) * list->size);
	   for(int i = 0, y = 1; i < list->size; i++, y++) {
		temp[y] = list->array[i]; 
	   }
	list->array = temp;
	}
	free(temp);
    }

    list->count -= 1;
    list->size -= 1;
    
    printf("Size: %i\n", list->size);
    printf("Count: %i\n", list->count);
    printf("Memory: %zu Bytes\n", sizeof(list->array) * sizeof(int) * list->size);

}

int main(void) 
{
    array_list* array1 = new_array_list(5);
    
    for(int i = 0; i < 10; i++) {
	array_list_add(array1, i + 1);
    }
     
    array_list_remove(array1, 0);
    array_list_remove(array1, 0);
    for(int i = 0; i < array1->count; i++ ) {
	printf("%i", array1->array[i]);
    }
    /*for(int i = 0; i < array1->count; i++) {
	printf("%i\n", array1->array[i]);
    }*/
    array_list_free(array1);
}








