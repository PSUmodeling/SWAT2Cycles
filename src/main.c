#include "swat2cycles.h"

int                 subbasin;
int                 hru;

int main (int argc, char *argv[])
{
    char            filename[MAXSTRING];
    FILE           *crop_file;
    FILE           *fert_file;
    FILE           *op_file;
    FILE           *plant_file;
    FILE           *till_file;
    FILE           *mgt_file;
    int             match;
    sllist_struct  *mgt_list;
    sllist_struct  *fert_list;
    sllist_struct  *plant_list;
    sllist_struct  *till_list;

    /*
     * Read command line arguments
     */
    if (argc < 3)
    {
        printf ("Please specify subbasin and HRU, using\n");
        printf ("./swat2cycles SUBBASIN HRU\n");
        exit (EXIT_FAILURE);
    }
    else if (argc > 3)
    {
        printf ("Too many input arguments.\n");
        exit (EXIT_FAILURE);
    }
    else
    {
        match = sscanf (argv[1], "%d", &subbasin);
        if (match != 1)
        {
            printf ("Error reading subbasin index from command line.\n");
            exit (EXIT_FAILURE);
        }

        match = sscanf (argv[2], "%d", &hru);
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
    strcpy (filename, "data/plant.dat");
    plant_file = fopen (filename, "r");
    if (NULL == plant_file)
    {
        printf ("\nError: Cannot find the specified plant file %s.\n",
            filename);
        exit (EXIT_FAILURE);
    }

    plant_list = SllistCreate ();
    ReadPlant (plant_file, plant_list);
    fclose (plant_file);

    /*
     * Read tillage file
     */
    strcpy (filename, "data/till.dat");
    till_file = fopen (filename, "r");
    if (NULL == till_file)
    {
        printf ("\nError: Cannot find the specified tillage file %s.\n",
            filename);
        exit (EXIT_FAILURE);
    }

    till_list = SllistCreate ();
    ReadTill (till_file, till_list);
    fclose (till_file);

    /*
     * Read fertilizer file
     */
    strcpy (filename, "data/fert.dat");
    fert_file = fopen (filename, "r");
    if (NULL == fert_file)
    {
        printf ("\nError: Cannot find the specified fertilizer file %s.\n",
            filename);
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
    sprintf (filename, "sb%dhru%d.crop", subbasin, hru);
    crop_file = fopen (filename, "w");
    if (NULL == plant_file)
    {
        printf ("\nError opening crop file %s.\n",
            filename);
        exit (EXIT_FAILURE);
    }

    sprintf (filename, "sb%dhru%d.operation", subbasin, hru);
    op_file = fopen (filename, "w");
    if (NULL == op_file)
    {
        printf ("\nError opening operation file %s.\n",
            filename);
        exit (EXIT_FAILURE);
    }

    WriteOp (op_file, mgt_list, crop_file, plant_list, fert_list, till_list);
    fclose (op_file);

    printf ("Operations have been written into %s.\n", filename);

    return (EXIT_SUCCESS);
}
