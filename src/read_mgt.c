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
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->oid, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 2 */
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->subbasin, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 3 */
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->hru, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 4 */
            sscanf (cmdstr + bytes_consumed, "%s%n", temp->landuse, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 5 */
            sscanf (cmdstr + bytes_consumed, "%s%n", temp->soil, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 6 */
            sscanf (cmdstr + bytes_consumed, "%s%n", temp->slope_cd, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 7 */
            sscanf (cmdstr + bytes_consumed, "%s%n", temp->crop, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 8 */
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->year, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 9 */
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->month, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 10 */
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->day, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 11 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->husc, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 12 */
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->mgt_op, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 13 */
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->headunits, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 14 */
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->plant_id, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 15 */
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->curyr_mat, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 16 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->lai_init, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 17 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->bio_init, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 18 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->hi_targ, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 19 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->bio_targ, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 20 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->cnop, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 21 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->irr_amt, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 22 */
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->fert_id, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 23 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->frt_kg, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 24 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->frt_surface, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 25 */
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->pest_id, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 26 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->pst_kg, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 27 */
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->tillage_id, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 28 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->harveff, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 29 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->hi_ovr, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 30 */
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->grz_days, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 31 */
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->manure_id, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 32 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->bio_eat, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 33 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->bio_trmp, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 34 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->manure_kg, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 35 */
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->wstrs_id, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 36 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->auto_wstrs, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 37 */
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->afert_id, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 38 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->auto_nstrs, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 39 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->auto_napp, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 40 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->auto_nyr, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 41 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->auto_eff, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 42 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->afrt_surface, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 43 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->sweepeff, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 44 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->fr_curb, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 45 */
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->imp_trig, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 46 */
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->fert_days, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 47 */
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->cfrt_id, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 48 */
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->ifrt_freq, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 49 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->cfrt_kg, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 50 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->pst_dep, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 51 */
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->ihv_gbm, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 52 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->irr_salt, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 53 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->irr_efm, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 54 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->irr_sq, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 55 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->irr_eff, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 56 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->irr_mx, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 57 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->irr_asq, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 58 */
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->cpst_id, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 59 */
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->pest_days, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 60 */
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->ipest_freq, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 61 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->cpst_kg, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 62 */
            sscanf (cmdstr + bytes_consumed, "%lf%n", &temp->burn_frlb, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 63 */
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->op_num, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 64 */
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->irr_sc, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 65 */
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->irr_no, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 66 */
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->irr_sca, &bytes_now);
            bytes_consumed += bytes_now;

            /* Col 67 */
            sscanf (cmdstr + bytes_consumed, "%d%n", &temp->irr_noa, &bytes_now);
            bytes_consumed += bytes_now;

            /* Add management record to lined list if needed */
            if (temp->subbasin == subbasin && temp->hru == hru)
            {
                AddMgt (mgt, temp);
            }
        }
    }

}
