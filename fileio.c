#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileio.h"


int file_exists(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file)
    {
        fclose(file);
        return 1;
    }
    return 0;
}


/*
 * Expected format:
 * day,period,faculty
 * 0,0,EMPTY
 */
int load_batch(const char *filename, BatchSlot batch[N][M])
{
    FILE *file = fopen(filename, "r");
    if (!file)
        return 0;

    char line[128];

    // Skip header
    fgets(line, sizeof(line), file);

    int day, period;
    char faculty[50];

    while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "%d,%d,%49[^\n]", &day, &period, faculty);
        strcpy(batch[day][period].faculty, faculty);
    }

    fclose(file);
    return 1;
}


int save_batch(const char *filename, BatchSlot batch[N][M])
{
    FILE *file = fopen(filename, "w");
    if (!file)
        return 0;

    fprintf(file, "day,period,faculty\n");

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            fprintf(file, "%d,%d,%s\n",
                    i, j,
                    batch[i][j].faculty);
        }
    }

    fclose(file);
    return 1;
}


/*
 * Expected format:
 * day,period,batch,subject
 * 0,0,EMPTY,EMPTY
 */
int load_faculty(const char *filename, FacultySlot faculty[N][M])
{
    FILE *file = fopen(filename, "r");
    if (!file)
        return 0;

    char line[128];

    // Skip header
    fgets(line, sizeof(line), file);

    int day, period;
    char batch_name[50];
    char subject[50];

    while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "%d,%d,%49[^,],%49[^\n]",
               &day, &period,
               batch_name, subject);

        strcpy(faculty[day][period].batch, batch_name);
        strcpy(faculty[day][period].subject, subject);
    }

    fclose(file);
    return 1;
}


int save_faculty(const char *filename, FacultySlot faculty[N][M])
{
    FILE *file = fopen(filename, "w");
    if (!file)
        return 0;

    fprintf(file, "day,period,batch,subject\n");

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            fprintf(file, "%d,%d,%s,%s\n",
                    i, j,
                    faculty[i][j].batch,
                    faculty[i][j].subject);
        }
    }

    fclose(file);
    return 1;
}
