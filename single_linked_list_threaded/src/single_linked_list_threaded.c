#include <pthread.h> 

#include "single_linked_list_threaded.h"

struct single_linked_list_threaded {
    struct node *head;
    pthread_mutex_t mutexLock;
};

struct node
{
    double value;
    struct node *next;
};

single_linked_list_threaded *
single_linked_list_threaded_create(void)
{
    single_linked_list_threaded *list = malloc(sizeof(*list));
    if(!list)
    {
        return NULL;
    }

    list->head = NULL;

    return list;
}


size_t
single_linked_list_threaded_size(const single_linked_list_threaded *list)
{
    if(!list)
    {
        return 0;
    }
    size_t len = 0;
    
    // Have to lock here since the head could move during the setup which would cause a bad count
    pthread_mutex_lock(&list->mutexLock); 
    
    struct node *currentNode = list->head;
    while(currentNode)
    {
        ++len;
        currentNode = currentNode->next;
    }
    
    pthread_mutex_unlock(&list->mutexLock);
    
    return len;
}

bool 
single_linked_list_threaded_append(single_linked_list_threaded *list, double value)
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
    
    // Iterate over the list to the last node and obtain the lock here so the head cant change after we start
    pthread_mutex_lock(&list->mutexLock); 
    
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
    
    pthread_mutex_unlock(&list->mutexLock);

    return true;
}

bool 
single_linked_list_threaded_prepend(single_linked_list_threaded *list, double value)
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
    
    pthread_mutex_lock(&list->mutexLock); 

    newNode->next = list->head;

    // Point old list head to new node
    list->head = newNode;
    
    pthread_mutex_unlock(&list->mutexLock);

    return true;
}

bool 
single_linked_list_threaded_insertAfterIndex(single_linked_list_threaded *list, double value, size_t idx)
{
    if(!list || !value)
    {
        return false;
    }
    
    // Locking here assures that the order and position of the list nodes dont change when iterating through it.
    pthread_mutex_lock(&list->mutexLock); 

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
    
    pthread_mutex_unlock(&list->mutexLock);

    return true;
}

double *
single_linked_list_threaded_fetch(single_linked_list_threaded *list, size_t idx)
{
    if(!list)
    {
        return NULL;
    }
    struct node *currentNode = list->head;

    pthread_mutex_lock(&list->mutexLock); 

    while (currentNode && idx > 0)
    {
        --idx;
        currentNode = currentNode->next;
    }

    // Release the lock here since we dont need it below and it has to be before the return
    pthread_mutex_unlock(&list->mutexLock);

    if (idx != 0)
    {
        return NULL;
    }

    return &currentNode->value;
}

void 
single_linked_list_threaded_destroy(single_linked_list_threaded *list){
    if(!list || !list->head)
    {
        return;
    }
    struct node *currentNode = list->head;

    pthread_mutex_lock(&list->mutexLock); 

    while(currentNode)
    {
        struct node *nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
    pthread_mutex_unlock(&list->mutexLock);
    pthread_mutex_destroy(list->head);
    free(list);

}