#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stddef.h>

typedef struct ArrayList ArrayList;

// constructor
ArrayList* alst_create();

// Add function
void alst_add(ArrayList *list, void* object);

// Get function
void* alst_get(ArrayList *list, size_t index);

// Size function
size_t alst_size(ArrayList *list);

// Remove function
void alst_remove_last(ArrayList *list);

// Remove object at index
void alst_remove_index(ArrayList *list, size_t index);

// Insert function at index
void alst_insert_index(ArrayList *list, void* object, size_t index);

// Set function at index
void alst_set_index(ArrayList *list, void* object, size_t index);

// Clear function
void alst_clear(ArrayList *list);

// Free function
void alst_free(ArrayList *list);

// Print function
void alst_print(ArrayList *list);

#endif