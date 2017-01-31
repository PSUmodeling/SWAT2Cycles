#ifndef SLLIST_H
#define SLLIST_H

/*****************************************************************************
 * The node structure
 *----------------------------------------------------------------------------
 * The purpose of this structure is to actually hold the data or "payload" to
 * be stored in the list. The nodes are connected sequentially, and thus each
 * node requires a second field to store the address of the next node.
 ****************************************************************************/
typedef struct lnode
{
    void           *data;
    struct lnode   *next;
}                   lnode_struct;

//typedef struct lnode    lnode_struct;

/*****************************************************************************
 * The list structure.
 *----------------------------------------------------------------------------
 * Metadata is contained here. A pointer to the first and last nodes in the
 * list allows for several operations to be performed more quickly. There is
 * also another pointer-to-node member variable for storing the location of a
 * "current" or active node that presumably will have operations performed on
 * it. Finally there is a size variable containing the total number of nodes.
 * Note that the first index of the list is considered index zero.
 ****************************************************************************/
typedef struct sllist_struct
{
    lnode_struct   *head;
    lnode_struct   *tail;
    lnode_struct   *current;
    int             size;
} sllist_struct;

sllist_struct* SllistCreate (void);
void SllistDestroy (sllist_struct *sllist);
int SllistPushFront ( sllist_struct *sllist, void *data);
int SllistPushBack (sllist_struct *sllist, void *data);
void* SllistPopFront(sllist_struct *sllist);
void* SllistPopBack(sllist_struct *sllist);
int SllistStep(sllist_struct *sllist);
void* SllistReadIndex(sllist_struct *sllist, int index);
int SllistInsertBefore(sllist_struct *sllist, int index, void *data);
int SllistInsertAfter(sllist_struct *sllist, int index, void *data);
void* SllistExtractAfter(sllist_struct *sllist, int index);

#endif
