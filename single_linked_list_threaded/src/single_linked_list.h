#ifndef SINGLE_LINKED_list_H
#define SINGLE_LINKED_list_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct single_linked_list single_linked_list;

/**
 * Creates a new single_linked_list object that is empty
 * @return the new single_linked_list, or NULL on error
 */
single_linked_list *
single_linked_list_create(void);

/**
 * Gets the number of a single_linked_list's items
 * @param the single_linked_list to inspect
 * @return the number of items
 */
size_t
single_linked_list_size(const single_linked_list *list);

/**
 * Append item to end of single_linked_list
 * @param the single_linked_list to modify
 * @param the value to append
 * @return true on success
 */
bool 
single_linked_list_append(single_linked_list *list, double value);

/**
 * Prepend item to beginning of single_linked_list
 * @param the single_linked_list to modify
 * @param the value to prepend
 * @return true on success
 */
bool 
single_linked_list_prepend(single_linked_list *list, double value);

/**
 * Inserts value after index idx
 * @param the single_linked_list to insert into
 * @param value to insert
 * @param 0-based index after which to insert value
 * @return true on success, false on failure (either
 * out-of-bounds or out of memory)
 *
 */
bool 
single_linked_list_insertAfterIndex(single_linked_list *list, double value, size_t idx);

/**
 * Get pointer to item from single_linked_list
 * @param the single_linked_list to inspect
 * @param the index to fetch
 * @return pointer to value fetched, or NULL
 */
double *
single_linked_list_fetch(single_linked_list *list, size_t idx);

// Since this single_linked_list stores the double data itself,
// there is no way to remove the scaffolding without
// also removing the data.
// void
// single_linked_list_disassemble(single_linked_list *);

/**
 * Destroy single_linked_list and free its memory
 * @param single_linked_list to destroy
 */
void 
single_linked_list_destroy(single_linked_list *list);

#endif