#ifndef TIMETABLE_H
#define TIMETABLE_H

#define M 4   // periods
#define N 5   // days
#define TOTAL_SLOTS (M * N)

#define EMPTY_STR "EMPTY"

// Represents one slot in a batch timetable
typedef struct {
    char faculty[50];
} BatchSlot;

// Represents one slot in a faculty timetable
typedef struct {
    char batch[50];
    char subject[50];
} FacultySlot;


/*
 * Converts a slot number (0 to TOTAL_SLOTS-1)
 * into day and period indices.
 */
void slot_to_indices(int slot, int *day, int *period);


/*
 * Checks if a slot is free in BOTH:
 *  - batch timetable
 *  - faculty timetable
 *
 * Returns:
 * 1 if free
 * 0 if not free
 */
int is_slot_free(BatchSlot batch[N][M],
                 FacultySlot faculty[N][M],
                 int day,
                 int period);


/*
 * Updates both batch and faculty timetables
 * for a given slot.
 */
void update_slot(BatchSlot batch[N][M],
                 FacultySlot faculty[N][M],
                 int day,
                 int period,
                 const char *faculty_name,
                 const char *batch_name,
                 const char *subject);


/*
 * Initializes batch timetable to EMPTY.
 * Useful when creating new files.
 */
void init_empty_batch(BatchSlot batch[N][M]);


/*
 * Initializes faculty timetable to EMPTY.
 */
void init_empty_faculty(FacultySlot faculty[N][M]);

#endif
