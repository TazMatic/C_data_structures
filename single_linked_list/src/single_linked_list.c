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
    return true;
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