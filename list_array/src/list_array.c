#include "list_array.h"

struct list_array
{
    size_t size;
    size_t capacity;
    void **data;
};

static const size_t DEFAULT_CAPACITY = 8;

static bool makeBigger(list_array *l);

list_array *
list_array_create(void)
{
    list_array *list = malloc(sizeof(*list));
    if (!list)
    {
        return NULL;
    }

    list->size = 0;
    list->capacity = DEFAULT_CAPACITY;
    list->data = malloc(list->capacity * sizeof(*list->data));
    if (!list->data)
    {
        free(list);
        return NULL;
    }

    return list;
}


size_t
list_array_size(const list_array *list)
{
    if(!list)
    {
        return 0;
    }
    return list->size;
}

bool 
list_array_append(list_array *list, void *value)
{
    if(!list)
    {
        return false;
    }
    if (list->size + 1 >= list->capacity)
    {
        bool success = makeBigger(list);
        if (!success)
        {
            return false;
        }
    }

    list->data[list->size++] = value;

    return true;
}

bool 
list_array_prepend(list_array *list, void *value)
{
    if(!list)
    {
        return false;
    }
    if (list->size == 0)
    {
        return list_array_append(list, value);
    }

    if (!list_array_append(list, list_array_fetch(list, list->size - 1)))
    {
        return false;
    }

    for (size_t n = list->size - 1; n > 0; --n)
    {
        list->data[n] = list->data[n-1];
    }

    list->data[0] = value;
    return true;
}

bool 
list_array_insertAfterIndex(list_array *list, void *value, size_t idx)
{
    if(!list || idx >= list->size)
    {
        return false;
    }
    if (!list_array_append(list, list_array_fetch(list, list->size - 1)))
    {
        return false;
    }

    for (size_t n = list->size - 1; n > idx+1; --n)
    {
        list->data[n] = list->data[n-1];
    }

    list->data[idx+1] = value;

    return true;
}

void *
list_array_fetch(list_array *list, size_t idx)
{
    if(!list || idx >= list->size)
    {
        return NULL;
    }
    return list->data[idx];
}

void 
list_array_destroy(list_array *list){
    if(!list)
    {
        return;
    }
    free(list->data);
    free(list);

}

static bool makeBigger(list_array *list)
{
  void *newData = realloc(list->data,
      2 * list->capacity * sizeof(*list->data));
  if (!newData)
  {
    return false;
  }

  list->capacity *= 2;
  list->data = newData;

  return true;
}