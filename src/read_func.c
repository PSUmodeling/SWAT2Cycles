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

int NextLine (FILE *fid, char *cmdstr, int *lno)
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
            return (-1);
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

    (*lno)++;

    return (0);
}

int ReadLine (char *cmdstr, char type, void *data, int *bytes_consumed,
        int *bytes_now)
{
    int             match;

    switch (type)
    {
        case 'd':
            match = sscanf (cmdstr + *bytes_consumed, "%lf%n", (double *)data,
                    bytes_now);
            (*bytes_consumed) += *bytes_now;
            break;
        case 'i':
            match = sscanf (cmdstr + *bytes_consumed, "%d%n", (int *)data,
                    bytes_now);
            (*bytes_consumed) += *bytes_now;
            break;
        case 's':
            match = sscanf (cmdstr + *bytes_consumed, "%s%n", (char *)data,
                    bytes_now);
            (*bytes_consumed) += *bytes_now;
            break;
        default:
            printf ("Error: Keyword type \'%c\' is not defined.\n", type);
            exit (EXIT_FAILURE);
    }

    if (1 == match)
    {
        return (0);
    }
    else
    {
        return (-1);
    }
}

int ReadDlmtdLine (char *cmdstr, char type, void *data, int *bytes_consumed,
        int *bytes_now)
{
    int             match;
    char            token[MAXSTRING];
    char            ch;
    int             i;

    for (i = 0; i < MAXSTRING - *bytes_consumed; i++)
    {
        ch = cmdstr[*bytes_consumed + i];

        if (',' == ch || '\r' == ch || '\n' == ch)
        {
            token[i] = '\0';
            break;
        }
        else
        {
            token[i] = ch;
        }
    }

    (*bytes_consumed) += i + 1;

    switch (type)
    {
        case 'd':
            match = sscanf (token, "%lf", (double *)data);
            break;
        case 'i':
            match = sscanf (token, "%d", (int *)data);
            break;
        case 's':
            match = sscanf (token, "%s", (char *)data);
            break;
        default:
            printf ("Error: Keyword type \'%c\' is not defined.\n", type);
            exit (EXIT_FAILURE);
    }

    if (1 == match)
    {
        return (0);
    }
    else
    {
        return (-1);
    }
}
