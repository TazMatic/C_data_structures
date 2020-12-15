#include "list_array.h"

struct list_array {
    struct node *head;
};

struct node
{
    double value;
    struct node *next;
};

list_array *
list_array_create(void)
{
    list_array *list = malloc(sizeof(*list));
    if(!list)
    {
        return NULL;
    }

    list->head = NULL;

    return list;
}


size_t
list_array_size(const list_array *list)
{
    if(!list)
    {
        return 0;
    }
    size_t len = 0;
    struct node *currentNode = list->head;
    while(currentNode)
    {
        ++len;
        currentNode = currentNode->next;
    }
    return len;
}

bool 
list_array_append(list_array *list, double value)
{
    if(!list || !value)
    {
        return false;
    }
    // Create the new node 
    struct node *newNode = malloc(sizeof(*newNode));
    if(!newNode)
    {
        return false;
    }
    newNode->value = value;
    newNode->next = NULL;
    // Iterate over the list to the last node
    struct node *currentNode = list->head;
    if(!currentNode)
    {
        list->head = newNode;
        return true;
    }
    while(currentNode->next)
    {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
    return true;
}

bool 
list_array_prepend(list_array *list, double value)
{
    if(!list || !value)
    {
        return false;
    }
    // Create the new node 
    struct node *newNode = malloc(sizeof(*newNode));
    if(!newNode)
    {
        return false;
    }
    newNode->value = value;
    newNode->next = list->head;

    // Point old list head to new node
    list->head = newNode;
    return true;
}

bool 
list_array_insertAfterIndex(list_array *list, double value, size_t idx)
{
    if(!list || !value)
    {
        return false;
    }
    struct node *currentNode = list->head;
    while (currentNode && idx > 0)
    {
        --idx;
        currentNode = currentNode->next;
    }
     if (!currentNode)
    {
        return false;
    }
    struct node *newNode = malloc(sizeof(*newNode));
    if (!newNode)
    {
        return false;
    }
    newNode->value = value;
    newNode->next = currentNode->next;

    currentNode->next = newNode;
    return true;
}

double *
list_array_fetch(list_array *list, size_t idx)
{
    if(!list)
    {
        return NULL;
    }
    struct node *currentNode = list->head;
    while (currentNode && idx > 0)
    {
        --idx;
        currentNode = currentNode->next;
    }
    if (idx != 0)
    {
        return NULL;
    }
    return &currentNode->value;
}

void 
list_array_destroy(list_array *list){
    if(!list || !list->head)
    {
        return;
    }
    struct node *currentNode = list->head;
    while(currentNode)
    {
        struct node *nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
    free(list);

}