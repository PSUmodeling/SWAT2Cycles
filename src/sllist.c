#include <stdlib.h>
#include "sllist.h"

/*****************************************************************************
 * Create a new list
 *----------------------------------------------------------------------------
 * Returns a pointer to a new, empty list. If allocation fails, returns NULL.
 ****************************************************************************/
sllist_struct* SllistCreate (void)
{
    sllist_struct  *sllist;

    sllist = malloc (sizeof (sllist_struct));

    if (sllist != NULL)
    {
        sllist->head = NULL;
        sllist->tail = NULL;
        sllist->current = NULL;
        sllist->size = 0;
    }

    return (sllist);
}

/*****************************************************************************
 * Destroy a list
 *----------------------------------------------------------------------------
 * Frees the memory of the list struct and all associated nodes.
 ****************************************************************************/
void SllistDestroy (sllist_struct *sllist)
{
    struct lnode   *save_next;

    sllist->current = sllist->head;

    while (sllist->current != NULL)
    {
        save_next = sllist->current->next;
        free (sllist->current->data);
        free (sllist->current);
        sllist->current = save_next;
    }

    free (sllist);
}

/*****************************************************************************
 * Prepend a node to the list
 *----------------------------------------------------------------------------
 * Adds a node to the front of the list. If allocation fails, returns -1,
 * otherwise returns 0.
 ****************************************************************************/
int SllistPushFront (sllist_struct *sllist, void *data)
{
    lnode_struct   *lnode;

    lnode = malloc (sizeof (lnode_struct));

    if (NULL == lnode)
    {
        return (-1);
    }

    lnode->data = data;
    lnode->next = sllist->head;
    sllist->head = lnode;

    if (0 == sllist->size)
    {
        sllist->tail = lnode;
    }

    sllist->size++;

    return (0);
}

/*****************************************************************************
 * Append node to a list
 *----------------------------------------------------------------------------
 * Adds a node to the end of the list. If allocation fails, returns -1,
 * otherwise returns 0.
 ****************************************************************************/
int SllistPushBack (sllist_struct *sllist, void *data)
{
    lnode_struct   *lnode;

    lnode = malloc (sizeof (lnode_struct));

    if (NULL == lnode)
    {
        return (-1);
    }

    lnode->data = data;
    lnode->next = NULL;

    if (0 == sllist->size)
    {
        sllist->head = lnode;
        sllist->tail = lnode;
    }
    else
    {
        sllist->tail->next = lnode;
        sllist->tail = lnode;
    }

    sllist->size++;

    return (0);
}

/*****************************************************************************
 * Extract the first node.
 *----------------------------------------------------------------------------
 * Remove the first node from the linked list, save a pointer to the data,
 * free the node (but do not free the data itself), and return a pointer to
 * the data so that it can be used. If the list is empty, returns NULL.
 ****************************************************************************/
void *SllistPopFront (sllist_struct *sllist)
{
    lnode_struct   *save_head;
    void           *data;

    if (0 == sllist->size)
    {
        return (NULL);
    }

    data = sllist->head->data;
    save_head = sllist->head;

    if (1 == sllist->size)
    {
        sllist->head = NULL;
        sllist->tail = NULL;
        /* Clear current since it shouldn't be used */
        sllist->current = NULL;
    }
    else
    {
        sllist->head = sllist->head->next;
    }
    free (save_head);
    sllist->size--;

    return (data);
}

/*****************************************************************************
 * Extract the last node
 *----------------------------------------------------------------------------
 * Remove the last node from the linked list, save a pointer to the data, free
 * the node (but do not free the data itself), and return a pointer to the
 * data so that it can be used. If the list is empty, returns NULL.
 ****************************************************************************/
void *SllistPopBack (sllist_struct *sllist)
{
    lnode_struct   *save_tail;
    lnode_struct   *new_tail;
    void           *data;

    if (0 == sllist->size)
    {
        return (NULL);
    }

    data = sllist->tail->data;
    save_tail = sllist->tail;

    if (1 == sllist->size)
    {
        sllist->head = NULL;
        sllist->tail = NULL;
        /* Clear current since it shouldn't be used */
        sllist->current = NULL;
    }
    else
    {
        new_tail = sllist->head;
        while (new_tail->next->next != NULL)
        {
            new_tail = new_tail->next;
        }
        sllist->tail = new_tail;
        sllist->tail->next = NULL;
    }
    free (save_tail);
    sllist->size--;

    return (data);
}

/*****************************************************************************
 * Step through a list
 *----------------------------------------------------------------------------
 * Changes the current node to the node after the current node. Returns 1 if
 * the current node is NULL.
 ****************************************************************************/
int SllistStep (sllist_struct *sllist)
{
    if (NULL == sllist->current)
    {
        return (1);
    }
    else
    {
        sllist->current = sllist->current->next;
        return (0);
    }
}

/*****************************************************************************
 * Access data by index
 *----------------------------------------------------------------------------
 * Returns a pointer to the payload of the node at the location specified by
 * the passed index value. The passed index value is interpreted as an offset
 * from index zero, the first node of the list. Returns NULL if the list is
 * empty or the index is out of range.
 ****************************************************************************/
void* SllistReadIndex (sllist_struct *sllist, int index)
{
    lnode_struct   *target;
    int             i;

    if (((sllist->size - index - 1) < 0) || (index < 0))
    {
        return (NULL);
    }

    target = sllist->head;
    for (i = 0; i < index; i++)
    {
        target = target->next;
    }

    return (target->data);
}

/*****************************************************************************
 * Insert a node before the node at the specified index
 *----------------------------------------------------------------------------
 * Adds a node before the passed node. If allocation fails, returns -1. If the
 * node doesn't exist in the list, returns 1. Otherwise, returns 0.
 ****************************************************************************/
int SllistInsertBefore (sllist_struct *sllist, int index, void *data)
{
    lnode_struct   *target;
    lnode_struct   *lnode;
    int             i;

    if (((sllist->size - index - 1) < 0) || (index < 0))
    {
        return (1);
    }

    if (0 == index)
    {
        SllistPushFront (sllist, data);
    }
    else
    {
        target = sllist->head;
        for (i = 0; i < index - 1; i++)
        {
            target = target->next;
        }

        lnode = malloc (sizeof (lnode_struct));
        if (NULL == lnode)
        {
            return (-1);
        }
        lnode->data = data;
        lnode->next = target->next;
        target->next = lnode;

        sllist->size++;
    }

    return (0);
}

/*****************************************************************************
 * Insert a node after the node at the specified index
 *----------------------------------------------------------------------------
 * Adds a node after the passed node. If allocation fails, returns -1. If the
 * node doesn't exist in the list, returns 1. Otherwise, returns 0.
 ****************************************************************************/
int SllistInsertAfter (sllist_struct *sllist, int index, void *data)
{
    int             i;
    lnode_struct   *target;
    lnode_struct   *lnode;

    if (((sllist->size - index - 1) < 0) || (index < 0))
    {
        return (1);
    }

    target = sllist->head;
    for (i = 0; i < index; i++)
    {
        target = target->next;
    }

    lnode = malloc (sizeof (struct lnode));
    if (NULL == lnode)
    {
        return (-1);
    }
    lnode->data = data;
    lnode->next = target->next;
    target->next = lnode;
    /* If inserting after tail */
    if (sllist->size - 1 == index)
    {
        sllist->tail = lnode;
    }
    sllist->size++;

    return (0);
}

/*****************************************************************************
 * Extract a node after the node at the specified index.
 *----------------------------------------------------------------------------
 * Remove the specified node from the linked list, save a pointer to the data,
 * free the node (but do not free the data itself), and return a pointer to
 * the data so that it can be used. If the list is empty or the node doesn't
 * exist in the list, returns NULL. Attempting to extract after the tail will
 * also return NULL.
 ****************************************************************************/
void* SllistExtractAfter (sllist_struct *sllist, int index)
{
    lnode_struct   *target;
    lnode_struct   *save_obsolete;
    void           *data;
    int             i;

    if (((sllist->size - index - 2) < 0) || (index < 0))
    {
        return (NULL);
    }

    target = sllist->head;

    for (i = 0; i < index; i++)
    {
        target = target->next;
    }

    /* If extracting tail */
    if (sllist->size - 1 == index)
    {
        sllist->tail = target;
    }

    data = target->next->data;
    save_obsolete = target->next;
    target->next = target->next->next;
    free (save_obsolete);
    sllist->size--;

    return (data);
}
