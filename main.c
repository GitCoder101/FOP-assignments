#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "timetable.h"
#include "fileio.h"
#include "ui.h"

int main()
{
    char faculty_name[50];
    char subject[50]; 
    char faculty_filename[100];
    char batch_filename[100];

    BatchSlot batch[N][M];
    FacultySlot faculty[N][M];

    printf("Enter Faculty Name: ");
    fgets(faculty_name, sizeof(faculty_name), stdin);

    faculty_name[strcspn(faculty_name, "\n")] = '\0';  // remove newline

    printf("Enter Subject Name: ");
    fgets(subject, sizeof(subject), stdin);

    subject[strcspn(subject, "\n")] = '\0';


    // Create faculty filename
    sprintf(faculty_filename, "faculty_%s.csv", faculty_name);

    // Load or create faculty file
    if (file_exists(faculty_filename))
    {
        load_faculty(faculty_filename, faculty);
    }
    else
    {
        init_empty_faculty(faculty);
        save_faculty(faculty_filename, faculty);
    }

    while (1)
    {
        int batch_choice = choose_batch();

        if (batch_choice == 0)
            break;

        sprintf(batch_filename, "batch%d.csv", batch_choice);

        // Load or create batch file
        if (file_exists(batch_filename))
        {
            load_batch(batch_filename, batch);
        }
        else
        {
            init_empty_batch(batch);
            save_batch(batch_filename, batch);
        }

        // Slot selection loop
        while (1)
        {
            display_union_view(batch, faculty);

            int slot = get_slot_input();

            if (slot == -1)
                break;

            if (slot < 0 || slot >= TOTAL_SLOTS)
            {
                printf("Invalid slot number.\n");
                continue;
            }

            int day, period;
            slot_to_indices(slot, &day, &period);

            if (!is_slot_free(batch, faculty, day, period))
            {
                printf("Slot not available.\n");
                continue;
            }

            update_slot(batch, faculty,
                        day, period,
                        faculty_name,
                        batch_filename,
                        subject);

            save_batch(batch_filename, batch);
            save_faculty(faculty_filename, faculty);

            printf("Slot successfully assigned.\n");
        }
    }

    printf("Session ended.\n");
    return 0;
}
