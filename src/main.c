#include "swat2cycles.h"

int main (int argc, char *argv[])
{
    char            filename[MAXSTRING];
    char            cmdstr[MAXSTRING];
    FILE           *mgt_file;
    int             i;
    int             subbasin;
    int             hru;
    int             match;
    sllist_struct  *mgt;
    mgt_struct     *record;

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

        printf ("Generating Cycles input files for subbasin %d, HRU %d.\n",
            subbasin, hru);
    }

    /* 
     * Open management file
     */
    strcpy (filename, "data/mgt2.txt");
    mgt_file = fopen (filename, "r");

    if (NULL == mgt_file)
    {
        printf ("\nError: Cannot find the specified management file %s.\n",
            filename);
        exit (EXIT_FAILURE);
    }

    /*
     * Read management file into a linked list
     */
    mgt = SllistCreate ();

    /* Skip header line of management file */
    NextLine (mgt_file, cmdstr);

    while (1)
    {
        /* Read a line of management file */
        NextLine (mgt_file, cmdstr);

        if (strncasecmp ("EOF", cmdstr, 3) != 0)
        {
            /* Parse one management record */
            record = (mgt_struct *) malloc (sizeof (mgt_struct));
            ReadMgt (cmdstr, record);

            /* Add management record to lined list if needed */
            if (record->subbasin == subbasin && record->hru == hru)
            {
                AddMgt (mgt, record);
            }
        }
        else
        {
            break;
        }
    }

    if (0 == mgt->size)
    {
        printf ("No management found for subbasin %d, HRU %d.\n",
            subbasin, hru);
    }
    else
    {
        mgt->current = mgt->head;
        for (i = 0; i < mgt->size; i++)
        {
            printf ("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1,
                ((mgt_struct *)mgt->current->data)->oid,
                ((mgt_struct *)mgt->current->data)->subbasin,
                ((mgt_struct *)mgt->current->data)->hru,
                ((mgt_struct *)mgt->current->data)->year,
                ((mgt_struct *)mgt->current->data)->month,
                ((mgt_struct *)mgt->current->data)->day);
                fflush (stdout);
            SllistStep (mgt);
        }
    }

    fclose (mgt_file);

    return (EXIT_SUCCESS);
}
