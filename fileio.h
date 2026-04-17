#ifndef FILEIO_H
#define FILEIO_H

#include "timetable.h"

/*
 * Returns 1 if file exists, 0 otherwise
 */
int file_exists(const char *filename);


/*
 * Load batch timetable from CSV file
 * Returns 1 on success, 0 on failure
 */
int load_batch(const char *filename, BatchSlot batch[N][M]);

/*
 * Save batch timetable to CSV file
 */
int save_batch(const char *filename, BatchSlot batch[N][M]);

/*
 * Load faculty timetable from CSV file
 * Returns 1 on success, 0 on failure
 */
int load_faculty(const char *filename, FacultySlot faculty[N][M]);

/*
 * Save faculty timetable to CSV file
 */
int save_faculty(const char *filename, FacultySlot faculty[N][M]);

#endif
