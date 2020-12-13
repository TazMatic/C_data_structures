#include "single_linked_list.h"

struct single_linked_list {
    struct node *head;
};

struct node
{
    double value;
    struct node *next;
};

single_linked_list *
single_linked_list_create(void)
{
    single_linked_list *list = malloc(sizeof(*list));
    if(!list)
    {
        return NULL;
    }

    list->head = NULL;

    return list;
}


size_t
single_linked_list_size(const single_linked_list *list)
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
single_linked_list_append(single_linked_list *list, double value)
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
single_linked_list_prepend(single_linked_list *list, double value)
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
single_linked_list_insertAfterIndex(single_linked_list *list, double value, size_t idx)
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
single_linked_list_fetch(single_linked_list *list, size_t idx)
{
    return 0;
}

void 
single_linked_list_destroy(single_linked_list *list){
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