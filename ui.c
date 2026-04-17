#include <stdio.h>
#include <string.h>
#include "ui.h"


void display_union_view(BatchSlot batch[N][M],
                        FacultySlot faculty[N][M])
{
    printf("\n========= SLOT VIEW =========\n");
    printf("Legend: FREE | OCCUPIED | BLOCKED\n\n");

    for (int slot = 0; slot < TOTAL_SLOTS; slot++)
    {
        int day = slot / M;
        int period = slot % M;

        printf("Slot %2d (Day %d, Period %d): ", slot, day, period);

        if (strcmp(faculty[day][period].batch, EMPTY_STR) != 0)
        {
            printf("BLOCKED (You already teach %s)\n",
                   faculty[day][period].batch);
        }
        else if (strcmp(batch[day][period].faculty, EMPTY_STR) != 0)
        {
            printf("OCCUPIED (By %s)\n",
                   batch[day][period].faculty);
        }
        else
        {
            printf("FREE\n");
        }
    }

    printf("\n");
}


int get_slot_input()
{
    int slot;
    printf("Enter slot number (0-%d) or -1 to stop selecting: ",
           TOTAL_SLOTS - 1);
    scanf("%d", &slot);
    return slot;
}


int choose_batch()
{
    int choice;

    printf("\n====== Select Batch ======\n");
    printf("1. batch1\n");
    printf("2. batch2\n");
    printf("3. batch3\n");
    printf("0. Exit\n");
    printf("Enter choice: ");

    scanf("%d", &choice);

    return choice;
}
