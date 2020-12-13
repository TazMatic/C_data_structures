#ifndef single_linked_list_threaded_H
#define single_linked_list_threaded_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct single_linked_list_threaded single_linked_list_threaded;

/**
 * Creates a new single_linked_list_threaded object that is empty
 * @return the new single_linked_list_threaded, or NULL on error
 */
single_linked_list_threaded *
single_linked_list_threaded_create(void);

/**
 * Gets the number of a single_linked_list_threaded's items
 * @param the single_linked_list_threaded to inspect
 * @return the number of items
 */
size_t
single_linked_list_threaded_size(const single_linked_list_threaded *list);

/**
 * Append item to end of single_linked_list_threaded
 * @param the single_linked_list_threaded to modify
 * @param the value to append
 * @return true on success
 */
bool 
single_linked_list_threaded_append(single_linked_list_threaded *list, double value);

/**
 * Prepend item to beginning of single_linked_list_threaded
 * @param the single_linked_list_threaded to modify
 * @param the value to prepend
 * @return true on success
 */
bool 
single_linked_list_threaded_prepend(single_linked_list_threaded *list, double value);

/**
 * Inserts value after index idx
 * @param the single_linked_list_threaded to insert into
 * @param value to insert
 * @param 0-based index after which to insert value
 * @return true on success, false on failure (either
 * out-of-bounds or out of memory)
 *
 */
bool 
single_linked_list_threaded_insertAfterIndex(single_linked_list_threaded *list, double value, size_t idx);

/**
 * Get pointer to item from single_linked_list_threaded
 * @param the single_linked_list_threaded to inspect
 * @param the index to fetch
 * @return pointer to value fetched, or NULL
 */
double *
single_linked_list_threaded_fetch(single_linked_list_threaded *list, size_t idx);

// Since this single_linked_list_threaded stores the double data itself,
// there is no way to remove the scaffolding without
// also removing the data.
// void
// single_linked_list_threaded_disassemble(single_linked_list_threaded *);

/**
 * Destroy single_linked_list_threaded and free its memory
 * @param single_linked_list_threaded to destroy
 */
void 
single_linked_list_threaded_destroy(single_linked_list_threaded *list);

#endif