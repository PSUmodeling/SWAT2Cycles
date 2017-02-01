#include "swat2cycles.h"

void ReadFert (FILE *fert_file, sllist_struct *fert)
{
    int             lno = 0;
    int             bytes_consumed;
    int             bytes_now;
    char            cmdstr[MAXSTRING];
    fert_struct    *temp;

    printf ("Reading fertilizer description file...\n");

    while (1)
    {
        /* Read one line of a fertilizer description */
        if (-1 == NextLine (fert_file, cmdstr, &lno))
        {
            break;
        }
        else
        {
            temp = (fert_struct *)malloc (sizeof (fert_struct));

            bytes_consumed = 0;
            bytes_now = 0;
            /* Col 1 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->ifnum, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading fertilizer file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 2 */
            if (-1 == ReadBuffer (cmdstr, 's', &temp->fertnm, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading fertilizer file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 3 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->fminn, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading fertilizer file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 4 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->fminp, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading fertilizer file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 5 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->forgn, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading fertilizer file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 6 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->forgp, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading fertilizer file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 7 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->fnh3n, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading fertilizer file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 8 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->bactpdb, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading fertilizer file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 9 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->bactlpdb, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading fertilizer file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 10 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->bactkddb, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading fertilizer file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
        }

        SllistPushBack (fert, temp);
    }

    printf ("%d fertilizer operations found.\n", fert->size);
}
