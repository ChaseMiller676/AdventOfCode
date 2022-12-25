/*
Solved!
*/
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
    FILE * tasks;
    char * line = NULL;
    size_t len = 0;

    tasks = fopen("./input", "r");
    if (tasks == NULL) {
	puts("File Not Found");
	return 1;
    }

    int taskPairs[4];
    int redundancies = 0;
    
    while (getline(&line, &len, tasks) != -1)
    {
	for (int i = 0; i < (int)strlen(line); i++) {
	    if (line[i] == ',' || line[i] == '-') {
		line[i] = ' ';
	    }
	}
	
	int i = 0;	
        char *start = line;
        char *eon;
        long value;
        errno = 0;
        while ((value = strtol(start, &eon, 0)),
	       eon != start &&
               !((errno == EINVAL && value == 0) ||
                 (errno == ERANGE && (value == LONG_MIN || value == LONG_MAX))))
        {


	    taskPairs[i] = value;
	    i++;
	    start = eon;
            errno = 0;
        }

	if ((taskPairs[0] >= taskPairs[2] && taskPairs[0] <= taskPairs[3]) ||
	    (taskPairs[1] >= taskPairs[2] && taskPairs[1] <= taskPairs[3]) ||
	    (taskPairs[2] >= taskPairs[0] && taskPairs[2] <= taskPairs[1]) ||
	    (taskPairs[3] >= taskPairs[0] && taskPairs[3] <= taskPairs[1])){
	    redundancies++;
	}
    }
    
    printf("Redundancies: %i\n", redundancies);

    fclose(tasks);

    return 0;
}
