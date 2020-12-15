#ifndef list_array_H
#define list_array_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct list_array list_array;

/**
 * Creates a new list_array object that is empty
 * @return the new list_array, or NULL on error
 */
list_array *
list_array_create(void);

/**
 * Gets the number of a list_array's items
 * @param the list_array to inspect
 * @return the number of items
 */
size_t
list_array_size(const list_array *list);

/**
 * Append item to end of list_array
 * @param the list_array to modify
 * @param the value to append
 * @return true on success
 */
bool 
list_array_append(list_array *list, double value);

/**
 * Prepend item to beginning of list_array
 * @param the list_array to modify
 * @param the value to prepend
 * @return true on success
 */
bool 
list_array_prepend(list_array *list, double value);

/**
 * Inserts value after index idx
 * @param the list_array to insert into
 * @param value to insert
 * @param 0-based index after which to insert value
 * @return true on success, false on failure (either
 * out-of-bounds or out of memory)
 *
 */
bool 
list_array_insertAfterIndex(list_array *list, double value, size_t idx);

/**
 * Get pointer to item from list_array
 * @param the list_array to inspect
 * @param the index to fetch
 * @return pointer to value fetched, or NULL
 */
double *
list_array_fetch(list_array *list, size_t idx);

// Since this list_array stores the double data itself,
// there is no way to remove the scaffolding without
// also removing the data.
// void
// list_array_disassemble(list_array *);

/**
 * Destroy list_array and free its memory
 * @param list_array to destroy
 */
void 
list_array_destroy(list_array *list);

#endif