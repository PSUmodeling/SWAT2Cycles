#include "swat2cycles.h"

void WriteOp (FILE *op_file, sllist_struct *mgt_list, FILE *crop_file,
    sllist_struct *plant_list, sllist_struct *fert_list,
    sllist_struct *till_list)
{
    int             i;
    mgt_struct     *mgt;
    plant_struct   *plant;
    fert_struct    *fert;
    till_struct    *till;

    if (0 == mgt_list->size)
    {
        printf ("No management found for subbasin %d, HRU %d.\n",
            subbasin, hru);
    }
    else
    {
        mgt_list->current = mgt_list->head;
        for (i = 0; i < mgt_list->size; i++)
        {
            mgt = (mgt_struct *)mgt_list->current->data;
            switch (mgt->mgt_op)
            {
                case END_OF_YEAR:
                    break;
                case PLANTING:
                    plant = FindPlant (plant_list, mgt->plant_id);
                    WritePlanting (op_file, mgt, plant);
                    if (0 == plant->flag)
                    {
                        //WriteCrop (crop_file, plant, mgt->heatunits,
                        //    mgt->hi_targ);
                    }
                    break;
                case IRRIGATION:
                    WriteIrr (op_file, mgt);
                    break;
                case FERTILIZER:
                    fert = FindFert (fert_list, mgt->fert_id);
                    WriteFert (op_file, mgt, fert);
                    break;
                case PESTICIDE:
                    printf ("Pesticide operation is not yet supported by"
                        "Cycles.\n");
                    printf ("OID %d is not written into Cycles input.\n",
                        mgt->oid);
                    printf ("\n");
                    break;
                case HARVEST_KILL:
                    WriteTill (op_file, mgt, NULL);
                    break;
                case TILLAGE:
                    till = FindTill (till_list, mgt->tillage_id);
                    WriteTill (op_file, mgt, till);
                    break;
                case HARVEST:
                    WriteTill (op_file, mgt, NULL);
                    break;
                case KILL:
                    WriteTill (op_file, mgt, NULL);
                    break;
                case GRAZING:
                    printf ("Grazing operation is not yet supported by"
                        "Cycles.\n");
                    printf ("OID %d is not written into Cycles input.\n",
                        mgt->oid);
                    printf ("\n");
                    break;
                case AUTO_IRR:
                    printf ("OID %d:\n", mgt->oid);
                    printf ("SWAT auto irrigation operations are different"
                        "from Cycles auto irrigation operations.\n");
                    printf ("Please manually add auto irrigation operations"
                        "to the operation file.\n");
                    printf ("\n");
                    break;
                case AUTO_FERT:
                    printf ("Auto fertilization is not yet supported by"
                        "Cycles.\n");
                    printf ("OID %d is not written into Cycles input.\n",
                        mgt->oid);
                    printf ("\n");
                    break;
                case STREET_SWEEP:
                    printf ("Street cleaning is not yet supported by"
                        "Cycles.\n");
                    printf ("OID %d is not written into Cycles input.\n",
                        mgt->oid);
                    printf ("\n");
                    break;
                case RELEASE_IMPOUND:
                    printf ("Release/impound is not yet supported by"
                        "Cycles.\n");
                    printf ("OID %d is not written into Cycles input.\n",
                        mgt->oid);
                    break;
                case CONT_FERT:
                    printf ("Continuous fertilizing is not yet supported by"
                        "Cycles.\n");
                    printf ("OID %d is not written into Cycles input.\n",
                        mgt->oid);
                    printf ("\n");
                    break;
                case CONT_PEST:
                    printf ("Pesticide operation is not yet supported by"
                        "Cycles.\n");
                    printf ("OID %d is not written into Cycles input.\n",
                        mgt->oid);
                    printf ("\n");
                    break;
                default:
                    break;
            }
            SllistStep (mgt_list);
        }
    }
}

plant_struct* FindPlant (sllist_struct *plant_list, int id)
{
    int             i;
    plant_struct   *temp;

    plant_list->current = plant_list->head;

    for (i = 0; i < plant_list->size; i++)
    {
        temp = (plant_struct *)plant_list->current->data;
        if (id == temp->icnum)
        {
            return (temp);
        }
        else
        {
            SllistStep (plant_list);
        }
    }

    printf ("Cannot find plant id %d in plant.dat.\n", id);
    exit (EXIT_FAILURE);
}

void WritePlanting (FILE *op_file, mgt_struct *mgt, plant_struct *plant)
{
    fprintf (op_file, "PLANTING\n");
    fprintf (op_file, "%-34s%d\n", "YEAR", mgt->year);
    fprintf (op_file, "%-34s%d\n", "DOY", DOY (mgt->month, mgt->day));
    fprintf (op_file, "%-34s%s\n", "CROP", plant->cpnm);
    fprintf (op_file, "%-34s%d\n", "USE_AUTO_IRR", 0);
    fprintf (op_file, "%-34s%d\n", "USE_AUTO_FERT", 0);
    fprintf (op_file, "%-34s%.1lf\n", "FRACTION", 1.0);
    fprintf (op_file, "%-34s%d\n", "CLIPPING_START", 1);
    fprintf (op_file, "%-34s%d\n", "CLIPPING_END", 366);
    fprintf (op_file, "\n");
}

void WriteIrr (FILE *op_file, mgt_struct *mgt)
{
    fprintf (op_file, "FIXED_IRRIGATION\n");
    fprintf (op_file, "%-34s%d\n", "YEAR", mgt->year);
    fprintf (op_file, "%-34s%d\n", "DOY", DOY (mgt->month, mgt->day));
    fprintf (op_file, "%-34s%.2lf\n", "VOLUME", mgt->irr_amt);
    fprintf (op_file, "\n");
}

fert_struct* FindFert (sllist_struct *fert_list, int id)
{
    int             i;
    fert_struct   *temp;

    fert_list->current = fert_list->head;

    for (i = 0; i < fert_list->size; i++)
    {
        temp = (fert_struct *)fert_list->current->data;
        if (id == temp->ifnum)
        {
            return (temp);
        }
        else
        {
            SllistStep (fert_list);
        }
    }

    printf ("Cannot find fertilizer id %d in fert.dat.\n", id);
    exit (EXIT_FAILURE);
}

till_struct* FindTill (sllist_struct *till_list, int id)
{
    int             i;
    till_struct   *temp;

    till_list->current = till_list->head;

    for (i = 0; i < till_list->size; i++)
    {
        temp = (till_struct *)till_list->current->data;
        if (id == temp->itnum)
        {
            return (temp);
        }
        else
        {
            SllistStep (till_list);
        }
    }

    printf ("Cannot find tillage id %d in till.dat.\n", id);
    exit (EXIT_FAILURE);
}

void WriteFert (FILE *op_file, mgt_struct *mgt, fert_struct *fert)
{
    fprintf (op_file, "FIXED_FERTILIZATION\n");
    fprintf (op_file, "%-34s%d\n", "YEAR", mgt->year);
    fprintf (op_file, "%-34s%d\n", "DOY", DOY (mgt->month, mgt->day));
    fprintf (op_file, "%-34s%s\n", "SOURCE", fert->fertnm);
    fprintf (op_file, "%-34s%.2lf\n", "MASS", mgt->frt_kg * 0.001);
    fprintf (op_file, "%-34s%s\n", "FORM", "LIQUID");
    fprintf (op_file, "%-34s%s\n", "METHOD", "BROADCAST");
    fprintf (op_file, "%-34s%d\n", "LAYER", (mgt->frt_surface > 0.5) ? 1 : 2);
    fprintf (op_file, "%-34s%.2lf\n", "C_ORGANIC", 0.0);
    fprintf (op_file, "%-34s%.2lf\n", "C_CHARCOAL", 0.0);
    fprintf (op_file, "%-34s%.2lf\n", "N_ORGANIC", fert->forgn);
    fprintf (op_file, "%-34s%.2lf\n", "N_CHARCOAL", 0.0);
    fprintf (op_file, "%-34s%.2lf\n", "N_NH4", fert->fminn * fert->fnh3n);
    fprintf (op_file, "%-34s%.2lf\n", "N_NO3", fert->fminn *
        (1.0 - fert->fnh3n));
    fprintf (op_file, "%-34s%.2lf\n", "P_ORGANIC", fert->forgp);
    fprintf (op_file, "%-34s%.2lf\n", "P_CHARCOAL", 0.0);
    fprintf (op_file, "%-34s%.2lf\n", "P_INORGANIC", fert->fminp);
    fprintf (op_file, "%-34s%.2lf\n", "K", 0.0);
    fprintf (op_file, "%-34s%.2lf\n", "S", 0.0);
    fprintf (op_file, "\n");
}

void WriteTill (FILE *op_file, mgt_struct *mgt, till_struct *till)
{
    double          depth;
    double          sdr;
    double          mxe;
    char            cropn[MAXSTRING];
    char            tool[MAXSTRING];
    int             grain_harvest;
    double          forage_harvest;

    switch (mgt->mgt_op)
    {
        case HARVEST_KILL:
            strcpy (cropn, "All");
            strcpy (tool, "Kill_Crop");
            grain_harvest = 0;
            forage_harvest = 0.0;
            depth = 0.0;
            sdr = 0.0;
            mxe = 0.0;
            break;
        case TILLAGE:
            strcpy (cropn, "N/A");
            strcpy (tool, till->tillnm);
            grain_harvest = 0;
            forage_harvest = 0.0;
            depth = till->deptil / 1000.0;
            sdr = 0.0;
            mxe = till->effmix;
            break;
        case HARVEST:
            strcpy (cropn, "All");
            if (mgt->ihv_gbm)
            {
                /* Grain harvest */
                strcpy (tool, "Grain_harvest");
                grain_harvest = 1;
                forage_harvest = 0.0;
            }
            else
            {
                strcpy (tool, "Forage_harvest");
                grain_harvest = 0;
                forage_harvest = mgt->harveff;
            }
            depth = 0.0;
            sdr = 0.0;
            mxe = 0.0;
            break;
        case KILL:
            strcpy (cropn, "All");
            strcpy (tool, "Kill_Crop");
            grain_harvest = 0;
            forage_harvest = 0.0;
            depth = 0.0;
            sdr = 0.0;
            mxe = 0.0;
            break;
        default:
            printf ("Application is not supported.\n");
    }

    fprintf (op_file, "TILLAGE\n");
    fprintf (op_file, "%-34s%d\n", "YEAR", mgt->year);
    fprintf (op_file, "%-34s%d\n", "DOY", DOY (mgt->month, mgt->day));
    fprintf (op_file, "%-34s%s\n", "TOOL", tool);
    fprintf (op_file, "%-34s%.2lf\n", "DEPTH", depth);
    fprintf (op_file, "%-34s%.2lf\n", "SOIL_DISTURB_RATIO", sdr);
    fprintf (op_file, "%-34s%.2lf\n", "MIXING_EFFICIENCY", mxe);
    fprintf (op_file, "%-34s%s\n", "CROP_NAME", cropn);
    fprintf (op_file, "%-34s%.2lf\n", "FRAC_THERMAL_TIME", 0.0);
    fprintf (op_file, "%-34s%.2lf\n", "KILL_EFFICIENCY", 0.0);
    fprintf (op_file, "%-34s%d\n", "GRAIN_HARVEST", grain_harvest);
    fprintf (op_file, "%-34s%.2lf\n", "FORAGE_HARVEST", forage_harvest);
    fprintf (op_file, "\n");
}

int DOY (int month, int mday)
{
    static const int days[13] = 
        {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

    if (2 == month && 29 == mday)
    {
        mday = 28;
    }

    return (days[month] + mday);
}
