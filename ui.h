#ifndef UI_H
#define UI_H

#include "timetable.h"

/*
 * Displays the union view of:
 * - batch timetable
 * - faculty timetable
 *
 * FREE      -> can select
 * OCCUPIED  -> batch already taken
 * BLOCKED   -> faculty already busy
 */
void display_union_view(BatchSlot batch[N][M],
                        FacultySlot faculty[N][M]);

/*
 * Prompts user to choose a slot number
 * Returns the slot number entered
 */
int get_slot_input();

/*
 * Prompts user to select a batch
 * Returns:
 * 1,2,3 for batch number
 * 0 to exit
 */
int choose_batch();

#endif
