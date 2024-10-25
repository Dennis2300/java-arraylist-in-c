#include "arraylist.h"
#include <stdio.h>
#include <stdlib.h>

// Constructor
struct ArrayList
{
    void **data;     // void pointer to store any type of data. using void for generic storage
    size_t size;     // current size of the arraylist
    size_t capacity; // total capacity of the arraylist
};

// Function to create an arraylist
ArrayList *alist_create()
{
    // allocate memory for the arraylist
    ArrayList *list = malloc(sizeof(ArrayList));
    // check if memory allocation failed
    if (!list)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    list->size = 0;      // initialize size to 0
    list->capacity = 10; // initialize capacity to 10
    // allocate memory for the data array
    list->data = malloc(list->capacity * sizeof(void *));
    // check if memory allocation failed
    if (!list->data)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return list;
}

// Function to add an object to the arraylist
void alist_add(ArrayList *list, void *object)
{
    // check if the size is greater than or equal to the capacity
    if (list->size >= list->capacity)
    {
        list->capacity *= 2;
        // reallocate memory for the data array
        list->data = realloc(list->data, list->capacity * sizeof(void *));
        // check if memory reallocation failed
        if (!list->data)
        {
            fprintf(stderr, "Memory reallocation failed!\n");
            exit(EXIT_FAILURE);
        }
    }
    // Assigns the object to the next available index in the data array and increments the size.
    list->data[list->size++] = object;
}

// Function to get an object at a specific index
void *alist_get(ArrayList *list, size_t index)
{
    // If the index is within the valid range, return the object at that index.
    if (index < list->size)
    {
        return list->data[index];
    }
    return NULL;
}

// Function to get the size of the arraylist
size_t alist_size(ArrayList *list)
{
    // return the size of the arraylist
    return list->size;
}

// Function to remove the last object from the arraylist
void *alist_remove_last(ArrayList *list)
{
    // If the size is 0, return NULL.
    if (list->size == 0)
    {
        return NULL;
    }
    // Return the last object in the arraylist and decrement the size.
    return list->data[--list->size];
}

// Function to remove an object at a specific index
void *alist_remove_index(ArrayList *list, size_t index)
{
    // If the index is greater than or equal to the size, return NULL.
    if (index >= list->size)
    {
        return NULL;
    }
    // Store the object to be removed.
    void *removedObject = list->data[index];
    // Shift the elements to the left starting from the index.
    for (size_t i = index; i < list->size - 1; i++)
    {
        list->data[i] = list->data[i + 1];
    }
    // Decrement the size
    list->size--;
    // return the removed object
    return removedObject;
}

// Function to insert an object at a specific index
void alist_insert_index(ArrayList *list, size_t index, void *object)
{
    // If the index is greater than the size, return.
    if (index > list->size)
    {
        return;
    }
    // If the size is greater than or equal to the capacity, reallocate memory.
    if (list->size >= list->capacity)
    {
        list->capacity *= 2;                                               // double the capacity
        list->data = realloc(list->data, list->capacity * sizeof(void *)); // reallocate memory
        // check if memory reallocation failed
        if (!list->data)
        {
            fprintf(stderr, "Memory reallocation failed!\n");
            exit(EXIT_FAILURE);
        }
    }
    // Shift the elements to the right starting from the index.
    for (size_t i = list->size; i > index; i--)
    {
        list->data[i] = list->data[i - 1]; // shift elements to the right
    }
    // Insert the object at the index and increment the size.
    list->data[index] = object;
    // increment the size
    list->size++;
}

// Function to set an object at a specific index
void alist_set(ArrayList *list, size_t index, void *object)
{
    // If the index is within the valid range, set the object at that index.
    if (index < list->size)
    {
        list->data[index] = object; // set the object at the index
    }
}

// Function to clear the arraylist
void alist_clear(ArrayList *list)
{
    list->size = 0; // set the size to 0
}

// Function to free the arraylist
void alist_free(ArrayList *list)
{
    free(list->data); // free the data array
    free(list);       // free the arraylist
}

// Function to print the arraylist
void alist_print(ArrayList *list)
{
    // Print the memory addresses of the objects in the arraylist.
    for (size_t i = 0; i < list->size; i++)
    {
        printf("%p ", list->data[i]); // print the memory address
    }
    printf("\n");
}

// Main function
int main()
{
    ArrayList *list = alist_create(); // create an arraylist

    // Add values to the arraylist
    for (int i = 1; i <= 5; i++)
    {                                     // add values from 1 to 5
        int *value = malloc(sizeof(int)); // allocate memory for the value
        *value = i;                       // set the value
        alist_add(list, value);           // add the value to the arraylist
    }
    alist_print(list);                      // print the arraylist
    int *valueAtIndex = alist_get(list, 2); // get the value at index 2
    if (valueAtIndex)
    {                                                    // check if the value is not NULL
        printf("Value at index 2: %d\n", *valueAtIndex); // print the value
    }
    int *removedValue = alist_remove_last(list);  // remove the last value
    printf("Removed value: %d\n", *removedValue); // print the removed value
    free(removedValue);                           // free the removed value
    int *newValue = malloc(sizeof(int));          // allocate memory for the new value
    *newValue = 99;                               // set the new value
    alist_insert_index(list, 1, newValue);        // insert the new value at index 1
    alist_print(list);                            // print the arraylist
    alist_clear(list);                            // clear the arraylist
    alist_free(list);                             // free the arraylist
    return 0;
}
