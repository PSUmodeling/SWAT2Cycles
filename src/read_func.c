#include "swat2cycles.h"

char FirstNonWhite (char *cmdstr)
{
    int             i;

    for (i = 0; i < strlen (cmdstr); i++)
    {
        if (32 == cmdstr[i] || '\t' == cmdstr[i])
        {
            continue;
        }
        else
        {
            break;
        }
    }

    return (cmdstr[i]);
}

int Readable (char *cmdstr)
{
    int             readable;
    char            ch;

    ch = FirstNonWhite (cmdstr);

    if (ch != '#' && ch != '\n' && ch != '\0' &&
        ch != '\t' && ch != '\r' && ch != ' ')
    {
        readable = 1;
    }
    else
    {
        readable = 0;
    }

    return (readable);
}

void NextLine (FILE *fid, char *cmdstr)
{
    /*
     * Read a non-blank line into cmdstr
     */

    int             j;
    strcpy (cmdstr, "\0");

    while (!Readable (cmdstr))
    {
        if (fgets (cmdstr, MAXSTRING, fid) == NULL)
        {
            strcpy (cmdstr, "EOF");
            break;
        }
        /* This is the special case to ignore the BOM mark */
        else if (strncasecmp ("\357\273\277", cmdstr, 3) == 0)
        {
            /* Copy from the fourth character (skip the first three) to
             * \000 */
            for (j = 0; j < strlen (cmdstr) - 3 + 1; j++)
            {
                cmdstr[j] = cmdstr[j + 3];
            }
        }
    }
}
