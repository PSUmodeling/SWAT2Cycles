#include "swat2cycles.h"

void ReadTill (FILE *till_file, sllist_struct *till)
{
    int             lno = 0;
    int             bytes_consumed;
    int             bytes_now;
    char            cmdstr[MAXSTRING];
    till_struct    *temp;

    printf ("Reading tillage description file...\n");

    while (1)
    {
        /* Read one line of a tillage description */
        if (-1 == NextLine (till_file, cmdstr, &lno))
        {
            break;
        }
        else
        {
            temp = (till_struct *)malloc (sizeof (till_struct));

            bytes_consumed = 0;
            bytes_now = 0;
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->itnum, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading tillage file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            if (-1 == ReadBuffer (cmdstr, 's', &temp->tillnm, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading tillage file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->effmix, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading tillage file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->deptil, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading tillage file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
        }

        SllistPushBack (till, temp);
    }

    printf ("%d tillage operations found.\n", till->size);
}
