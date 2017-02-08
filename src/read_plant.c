#include "swat2cycles.h"

void ReadPlant (FILE *plant_file, sllist_struct *plant)
{
    int             i;
    int             lno = 0;
    int             bytes_consumed;
    int             bytes_now;
    char            cmdstr[MAXSTRING];
    plant_struct   *temp;

    printf ("Reading plant description file...\n");

    while (1)
    {
        /* Read first line of a plant description */
        if (-1 == NextLine (plant_file, cmdstr, &lno))
        {
            break;
        }
        else
        {
            temp = (plant_struct *)malloc (sizeof (plant_struct));

            bytes_consumed = 0;
            bytes_now = 0;
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->icnum, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            if (-1 == ReadBuffer (cmdstr, 's', &temp->cpnm, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->idc, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
        }

        /* Read second line of a plant description */
        if (-1 == NextLine (plant_file, cmdstr, &lno))
        {
            break;
        }
        else
        {
            bytes_consumed = 0;
            bytes_now = 0;

            /* Initialize flag */
            temp->flag = 0;

            /* Col 1*/
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->bio_e, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 2 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->hvsti, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 3 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->blai, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 4 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->frgrw1, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 5 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->laimx1, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 6 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->frgrw2, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 7 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->laimx2, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 8 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->dlai, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 9 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->chtmx, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 10 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->rdmx, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
        }

        /* Read third line of a plant description */
        if (-1 == NextLine (plant_file, cmdstr, &lno))
        {
            break;
        }
        else
        {
            bytes_consumed = 0;
            bytes_now = 0;
            /* Col 1*/
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->t_opt, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 2 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->t_base, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 3 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->cnyld, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 4 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->cpyld, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 5--7 */
            for (i = 0; i < 3; i++)
            {
                if (-1 == ReadBuffer (cmdstr, 'd', &temp->pltnfr[i],
                    &bytes_consumed, &bytes_now))
                {
                    printf ("Error reading plant file at Line %d\n", lno);
                    exit (EXIT_FAILURE);
                }
            }
            /* Col 8--10 */
            for (i = 0; i < 3; i++)
            {
                if (-1 == ReadBuffer (cmdstr, 'd', &temp->pltpfr[i],
                    &bytes_consumed, &bytes_now))
                {
                    printf ("Error reading plant file at Line %d\n", lno);
                    exit (EXIT_FAILURE);
                }
            }
        }

        /* Read fourth line of a plant description */
        if (-1 == NextLine (plant_file, cmdstr, &lno))
        {
            break;
        }
        else
        {
            bytes_consumed = 0;
            bytes_now = 0;
            /* Col 1*/
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->wsyf, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 2 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->usle_c, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 3 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->gsi, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 4 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->vpdfr, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 5 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->frgmax, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 6 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->wavp, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 7 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->co2hi, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 8 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->bioehi, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 9 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->rsdco_pl, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 10 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->alai_min, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
        }

        /* Read fifth line of a plant description */
        if (-1 == NextLine (plant_file, cmdstr, &lno))
        {
            break;
        }
        else
        {
            bytes_consumed = 0;
            bytes_now = 0;
            /* Col 1*/
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->bio_leaf, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 2 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->mat_yrs, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 3 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->bmx_trees, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 4 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->ext_coef, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
            /* Col 5 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->bmdieoff, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading plant file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }
        }

        SllistPushBack (plant, temp);
    }

    printf ("%d plant types found.\n", plant->size);
    printf ("\n");
}
