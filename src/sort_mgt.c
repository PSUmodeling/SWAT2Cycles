#include "swat2cycles.h"

int AddMgt (sllist_struct *sllist, mgt_struct *op)
{
    lnode_struct   *target;
    int             pos;
    int             index;

    /* Special case: sllist is empty */
    if (0 == sllist->size)
    {
        SllistPushFront (sllist, op);
        return (1);
    }
    /* Special case: sllist has one element */
    else if (1 == sllist->size)
    {
        pos = SortMgt ((mgt_struct *)sllist->head->data, op);
        if (AHEAD == pos)
        {
            SllistPushFront (sllist, op);
            return (1);
        }
        else
        {
            SllistPushBack (sllist, op);
            return (1);
        }
    }
    else
    {
        target = sllist->head;
        index = 0;

        while(index < sllist->size)
        {
            pos = SortMgt ((mgt_struct *)target->data, op);
            if (AHEAD == pos)
            {
                SllistInsertBefore (sllist, index, op);
                return (1);
            }
            else
            {
                target = target->next;
                index++;
            }
        }

        SllistPushBack (sllist, op);
        return (1);
    }
}

int SortMgt (mgt_struct *op1, mgt_struct *op2)
{
    /* Rank management by subbasin, hru, year, month, and day */
    if (op2->subbasin > op1->subbasin)
    {
        return (BEHIND);
    }
    if (op2->subbasin < op1->subbasin)
    {
        return (AHEAD);
    }

    if (op2->hru > op1->hru)
    {
        return (BEHIND);
    }
    if (op2->hru < op1->hru)
    {
        return (AHEAD);
    }

    if (op2->year > op1->year)
    {
        return (BEHIND);
    }
    if (op2->year < op1->year)
    {
        return (AHEAD);
    }

    if (op2->month > op1->month)
    {
        return (BEHIND);
    }
    if (op2->month < op1->month)
    {
        return (AHEAD);
    }

    if (op2->day > op1->day)
    {
        return (BEHIND);
    }
    if (op2->day < op1->day)
    {
        return (AHEAD);
    }

    return (BEHIND);
}
