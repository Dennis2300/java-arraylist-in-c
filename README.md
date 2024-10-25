# ArrayList in C

This repository contains a array list implementation in C, mimicking the functionality of Java's `ArrayList`.

## Functions

The following functions are available in this implementation:

- `ArrayList* alist_create()`: Creates and initializes a new `ArrayList`.
- `void alist_add(ArrayList *list, void *object)`: Adds an object to the end of the list.
- `void* alist_get(ArrayList *list, size_t index)`: Retrieves an object at the specified index.
- `size_t alist_size(ArrayList *list)`: Returns the current number of elements in the list.
- `void* alist_remove_last(ArrayList *list)`: Removes and returns the last object in the list.
- `void* alist_remove_index(ArrayList *list, size_t index)`: Removes and returns the object at the specified index.
- `void alist_insert_index(ArrayList *list, size_t index, void *object)`: Inserts an object at the specified index.
- `void alist_set(ArrayList *list, size_t index, void *object)`: Sets the object at the specified index to a new object.
- `void alist_clear(ArrayList *list)`: Clears the list, resetting its size to 0.
- `void alist_free(ArrayList *list)`: Frees the memory allocated for the `ArrayList`.
- `void alist_print(ArrayList *list)`: Prints the contents of the list.

