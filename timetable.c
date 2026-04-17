#include <stdio.h>
#include <string.h>
#include "timetable.h"


void slot_to_indices(int slot, int *day, int *period)
{
    *day = slot / M;
    *period = slot % M;
}


int is_slot_free(BatchSlot batch[N][M],
                 FacultySlot faculty[N][M],
                 int day,
                 int period)
{
    if (strcmp(batch[day][period].faculty, EMPTY_STR) != 0)
        return 0;

    if (strcmp(faculty[day][period].batch, EMPTY_STR) != 0)
        return 0;

    return 1;
}


void update_slot(BatchSlot batch[N][M],
                 FacultySlot faculty[N][M],
                 int day,
                 int period,
                 const char *faculty_name,
                 const char *batch_name,
                 const char *subject)
{
    // Update batch timetable (store faculty name)
    strcpy(batch[day][period].faculty, faculty_name);

    // Update faculty timetable (store batch + subject)
    strcpy(faculty[day][period].batch, batch_name);
    strcpy(faculty[day][period].subject, subject);
}


void init_empty_batch(BatchSlot batch[N][M])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            strcpy(batch[i][j].faculty, EMPTY_STR);
        }
    }
}


void init_empty_faculty(FacultySlot faculty[N][M])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            strcpy(faculty[i][j].batch, EMPTY_STR);
            strcpy(faculty[i][j].subject, EMPTY_STR);
        }
    }
}
