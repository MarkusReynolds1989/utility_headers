#include <stdio.h>
#include <stdlib.h>

typedef struct array_list
{
    int size;
    int count;
    int *array;
} array_list;

array_list *new_array_list(int size)
{
    array_list *output = (array_list *)calloc(size, sizeof(array_list));
    output->array = (int *)calloc(size, sizeof(int));
    output->count = 0;
    output->size = size - 1;
    return output;
}

void array_list_free(array_list *list)
{
    free(list->array);
    free(list);
}

void array_list_realloc(array_list *list)
{
    list->array = realloc(list->array, sizeof(int *) * list->size);
}

void array_list_add(array_list *list, int input)
{
    if (list->count <= list->size)
    {
        list->array[list->count] = input;
    }
    else
    {
        list->array = realloc(list->array, sizeof(int *) * list->size + 1);
        list->array[list->count] = input;
        list->size += 1;
    }

    list->count += 1;
}

void array_list_remove(array_list *list, int index)
{
    if (index >= list->count)
    {
        int *temp = (int *)calloc(list->size, sizeof(int));
        array_list_realloc(list);
        // Process the list size.
        if (index == 0)
        {
            for (int i = 0, y = 1; i < list->size; i++, y++)
            {
                temp[y] = list->array[i];
            }
            list->array = temp;
        }

        if (index == list->count)
        {
            for (int i = 0; i < list->count - 1; i++)
            {
                temp[i] = list->array[i];
            }
            list->array = temp;
        }

        else
        {
            for (int i = 0; i < index; i++)
            {
                temp[i] = list->array[i];
            }
            for (int i = index + 1; i <= list->count; i++)
            {
                temp[i] = list->array[i];
            }
        }

        free(temp);
    }

    list->count -= 1;
    list->size -= 1;
}

int main(void)
{
    array_list *array1 = new_array_list(5);

    for (int i = 1; i <= 7; i++)
    {
        array_list_add(array1, i);
    }

    array_list_remove(array1, 0);

    for (int i = 0; i < array1->count; i++)
    {
        printf("%i\n", array1->array[i]);
    }

    array_list_free(array1);
}
