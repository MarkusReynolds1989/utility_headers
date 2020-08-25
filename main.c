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
    output->count = -1;
    output->size = size;
    return output;
}

void increase_array(array_list* input)
{
   input->size += 1;
   input->array = realloc(input->array, sizeof(int) * input->size + 1); 
}

void decrease_array(array_list* input)
{
    if(input->size > 0) {
	input->size -= 1;
	input->array = realloc(input->array, sizeof(int) * input->size - 1);
    }
}

void array_list_add(array_list* list, int input) {
    if(list->count + 1 <= list->size){ 
	list->count += 1;
	list->array[list->count] = input;
    }
    else {
	increase_array(list);
	list->count += 1;
	list->array[list->count] = input;
    }
}

void array_list_remove(array_list* list, int index) {
    int* temp = (int*)calloc(list->size, sizeof(int));
    
    //  First.
    if(index == 0) {
	for(int i = 1; i < list->size; i++) {
	    temp[i] = list->array[i];
	}
    }
    
    // Last. 
    if(index == list->size) {
	for(int i = 0; i < list->size; i++) {
	    temp[i] = list->array[i];
	}
    }
    
    // Else
    else {
	for(int i = 0; i < index - 1; i++) {
	    temp[i] = list->array[i]; 
	}
	for(int i = index + 1; i < list->size; i++) {
	    temp[i] = list->array[i];
	}
    }

    decrease_array(list);
    list->count -=1;
    list->array = temp;
    free(temp);
}


int main(void) 
{
    array_list* array1 = new_array_list(5);
    
    for(int i = 0; i <= 20; i++) {
	array_list_add(array1, i);
    }

    array_list_remove(array1, 0);

    for(int i = 0; i < array1->size; i++) {
	printf("%i\n", array1->array[i]);
    }

    free(array1);
}








