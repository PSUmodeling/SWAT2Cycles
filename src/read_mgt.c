#include "swat2cycles.h"

void ReadMgt (char *cmdstr, mgt_struct *mgt)
{
    int             bytes_now;
    int             bytes_consumed = 0;

    /* Col 1 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->oid, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 2 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->subbasin, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 3 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->hru, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 4 */
    sscanf (cmdstr + bytes_consumed, "%s%n", mgt->landuse, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 5 */
    sscanf (cmdstr + bytes_consumed, "%s%n", mgt->soil, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 6 */
    sscanf (cmdstr + bytes_consumed, "%s%n", mgt->slope_cd, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 7 */
    sscanf (cmdstr + bytes_consumed, "%s%n", mgt->crop, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 8 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->year, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 9 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->month, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 10 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->day, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 11 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->husc, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 12 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->mgt_op, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 13 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->headunits, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 14 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->plant_id, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 15 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->curyr_mat, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 16 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->lai_init, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 17 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->bio_init, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 18 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->hi_targ, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 19 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->bio_targ, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 20 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->cnop, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 21 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->irr_amt, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 22 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->fert_id, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 23 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->frt_kg, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 24 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->frt_surface, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 25 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->pest_id, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 26 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->pst_kg, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 27 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->tillage_id, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 28 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->harveff, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 29 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->hi_ovr, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 30 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->grz_days, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 31 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->manure_id, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 32 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->bio_eat, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 33 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->bio_trmp, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 34 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->manure_kg, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 35 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->wstrs_id, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 36 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->auto_wstrs, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 37 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->afert_id, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 38 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->auto_nstrs, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 39 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->auto_napp, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 40 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->auto_nyr, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 41 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->auto_eff, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 42 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->afrt_surface, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 43 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->sweepeff, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 44 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->fr_curb, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 45 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->imp_trig, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 46 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->fert_days, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 47 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->cfrt_id, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 48 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->ifrt_freq, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 49 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->cfrt_kg, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 50 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->pst_dep, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 51 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->ihv_gbm, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 52 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->irr_salt, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 53 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->irr_efm, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 54 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->irr_sq, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 55 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->irr_eff, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 56 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->irr_mx, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 57 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->irr_asq, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 58 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->cpst_id, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 59 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->pest_days, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 60 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->ipest_freq, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 61 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->cpst_kg, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 62 */
    sscanf (cmdstr + bytes_consumed, "%lf%n", &mgt->burn_frlb, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 63 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->op_num, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 64 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->irr_sc, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 65 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->irr_no, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 66 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->irr_sca, &bytes_now);
    bytes_consumed += bytes_now;

    /* Col 67 */
    sscanf (cmdstr + bytes_consumed, "%d%n", &mgt->irr_noa, &bytes_now);
    bytes_consumed += bytes_now;
}
