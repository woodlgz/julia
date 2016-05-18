#include "list.h"

#include <assert.h>

int list_insert(list_t* list, list_node_t* pos, void* x)
{
    assert(pos != NULL);
    list_node_t* new_node = pool_alloc(list->pool);
    if (new_node == NULL)
        return ERROR;
    
    new_node->data = x;
    new_node->next = pos->next;
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
    new_node->prev = pos;
    pos->next = new_node;
    
    ++list->size;
    return OK;
}

int list_delete(list_t* list, list_node_t* x)
{    
    assert(list->size > 0 && x != &list->dummy);
    x->prev->next = x->next;
    if (x->next != NULL)
        x->next->prev = x->prev;

    pool_free(list->pool, x);
    --list->size;
    return OK;
}
