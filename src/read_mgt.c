#include "swat2cycles.h"

void ReadMgt (FILE *mgt_file, sllist_struct *mgt)
{
    int             bytes_now;
    int             bytes_consumed;
    char            cmdstr[MAXSTRING];
    int             lno = 0;
    mgt_struct     *temp;

    /* Skip header line of management file */
    NextLine (mgt_file, cmdstr, &lno);

    while (1)
    {
        /* Read a line of management file */
        if (-1 == NextLine (mgt_file, cmdstr, &lno))
        {
            break;
        }
        else
        {
            /* Parse one management record */
            temp = (mgt_struct *) malloc (sizeof (mgt_struct));
            bytes_consumed = 0;

            /* Col 1 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->oid, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 2 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->subbasin, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 3 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->hru, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 4 */
            if (-1 == ReadBuffer (cmdstr, 's', temp->landuse, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 5 */
            if (-1 == ReadBuffer (cmdstr, 's', temp->soil, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 6 */
            if (-1 == ReadBuffer (cmdstr, 's', temp->slope_cd, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 7 */
            if (-1 == ReadBuffer (cmdstr, 's', temp->crop, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 8 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->year, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 9 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->month, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 10 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->day, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 11 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->husc, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 12 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->mgt_op, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 13 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->heatunits, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 14 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->plant_id, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 15 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->curyr_mat, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 16 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->lai_init, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 17 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->bio_init, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 18 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->hi_targ, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 19 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->bio_targ, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 20 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->cnop, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 21 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->irr_amt, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 22 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->fert_id, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 23 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->frt_kg, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 24 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->frt_surface, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 25 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->pest_id, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 26 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->pst_kg, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 27 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->tillage_id, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 28 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->harveff, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 29 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->hi_ovr, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 30 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->grz_days, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 31 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->manure_id, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 32 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->bio_eat, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 33 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->bio_trmp, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 34 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->manure_kg, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 35 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->wstrs_id, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 36 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->auto_wstrs, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 37 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->afert_id, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 38 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->auto_nstrs, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 39 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->auto_napp, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 40 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->auto_nyr, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 41 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->auto_eff, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 42 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->afrt_surface, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 43 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->sweepeff, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 44 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->fr_curb, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 45 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->imp_trig, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 46 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->fert_days, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 47 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->cfrt_id, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 48 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->ifrt_freq, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 49 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->cfrt_kg, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 50 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->pst_dep, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 51 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->ihv_gbm, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 52 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->irr_salt, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 53 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->irr_efm, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 54 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->irr_sq, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 55 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->irr_eff, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 56 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->irr_mx, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 57 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->irr_asq, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 58 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->cpst_id, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 59 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->pest_days, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 60 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->ipest_freq, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 61 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->cpst_kg, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 62 */
            if (-1 == ReadBuffer (cmdstr, 'd', &temp->burn_frlb, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 63 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->op_num, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 64 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->irr_sc, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 65 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->irr_no, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 66 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->irr_sca, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Col 67 */
            if (-1 == ReadBuffer (cmdstr, 'i', &temp->irr_noa, &bytes_consumed,
                &bytes_now))
            {
                printf ("Error reading management file at Line %d\n", lno);
                exit (EXIT_FAILURE);
            }

            /* Add management record to lined list if needed */
            if (temp->subbasin == subbasin && temp->hru == hru)
            {
                AddMgt (mgt, temp);
            }
        }
    }

}
