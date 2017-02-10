#include "swat2cycles.h"

int                 subbasin;
int                 hru;
char                filename[MAXSTRING];

int main (int argc, char *argv[])
{
    FILE           *crop_file;
    FILE           *fert_file;
    FILE           *op_file;
    FILE           *plant_file;
    FILE           *till_file;
    FILE           *mgt_file;
    int             match;
    char            plantfn[MAXSTRING];
    char            tillfn[MAXSTRING];
    char            fertfn[MAXSTRING];
    char            cropfn[MAXSTRING];
    char            opfn[MAXSTRING];
    sllist_struct  *mgt_list;
    sllist_struct  *fert_list;
    sllist_struct  *plant_list;
    sllist_struct  *till_list;

    /*
     * Read command line arguments
     */
    if (argc < 4)
    {
        printf ("Please specify management file, subbasin and HRU, using\n");
        printf ("./swat2cycles FILE_NAME SUBBASIN HRU\n");
        exit (EXIT_FAILURE);
    }
    else if (argc > 4)
    {
        printf ("Too many input arguments.\n");
        exit (EXIT_FAILURE);
    }
    else
    {
        strcpy (filename, argv[1]);

        match = sscanf (argv[2], "%d", &subbasin);
        if (match != 1)
        {
            printf ("Error reading subbasin index from command line.\n");
            exit (EXIT_FAILURE);
        }

        match = sscanf (argv[3], "%d", &hru);
        if (match != 1)
        {
            printf ("Error reading HRU index from command line.\n");
            exit (EXIT_FAILURE);
        }

        printf ("Generating Cycles input files for subbasin %d, HRU %d.\n\n",
            subbasin, hru);
    }

    /*
     * Read plant file
     */
    strcpy (plantfn, "data/plant.dat");
    plant_file = fopen (plantfn, "r");
    if (NULL == plant_file)
    {
        printf ("\nError: Cannot find the specified plant file %s.\n",
            plantfn);
        exit (EXIT_FAILURE);
    }

    plant_list = SllistCreate ();
    ReadPlant (plant_file, plant_list);
    fclose (plant_file);

    /*
     * Read tillage file
     */
    strcpy (tillfn, "data/till.dat");
    till_file = fopen (tillfn, "r");
    if (NULL == till_file)
    {
        printf ("\nError: Cannot find the specified tillage file %s.\n",
            tillfn);
        exit (EXIT_FAILURE);
    }

    till_list = SllistCreate ();
    ReadTill (till_file, till_list);
    fclose (till_file);

    /*
     * Read fertilizer file
     */
    strcpy (fertfn, "data/fert.dat");
    fert_file = fopen (fertfn, "r");
    if (NULL == fert_file)
    {
        printf ("\nError: Cannot find the specified fertilizer file %s.\n",
            fertfn);
        exit (EXIT_FAILURE);
    }

    fert_list = SllistCreate ();
    ReadFert (fert_file, fert_list);
    fclose (fert_file);

    /*
     * Read management file
     */
    strcpy (filename, "data/mgt.txt");
    mgt_file = fopen (filename, "r");
    if (NULL == mgt_file)
    {
        printf ("\nError: Cannot find the specified management file %s.\n",
            filename);
        exit (EXIT_FAILURE);
    }

    /* Read management file into a linked list */
    mgt_list = SllistCreate ();
    ReadMgt (mgt_file, mgt_list);
    fclose (mgt_file);

    if (mgt_list->size == 0)
    {
        printf ("No management record found for subbasin %d, HRU %d.\n",
            subbasin, hru);
        exit (EXIT_SUCCESS);
    }

    printf ("%d management records found for Subbasin %d, HRU %d.\n",
        mgt_list->size, subbasin, hru);
    printf ("\n");

    /*
     * Write Cycles operation file
     */
    sprintf (cropfn, "sb%dhru%d.crop", subbasin, hru);
    crop_file = fopen (cropfn, "w");
    if (NULL == plant_file)
    {
        printf ("\nError opening crop file %s.\n",
            cropfn);
        exit (EXIT_FAILURE);
    }

    sprintf (opfn, "sb%dhru%d.operation", subbasin, hru);
    op_file = fopen (opfn, "w");
    if (NULL == op_file)
    {
        printf ("\nError opening operation file %s.\n",
            opfn);
        exit (EXIT_FAILURE);
    }

    WriteOp (op_file, mgt_list, crop_file, plant_list, fert_list, till_list);
    fclose (op_file);

    printf ("Operations have been written into %s.\n", opfn);

    return (EXIT_SUCCESS);
}
