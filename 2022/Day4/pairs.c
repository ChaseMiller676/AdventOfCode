#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int containsRedundancy(int taskPairs[4]) {
    if (taskPairs[2] >= taskPairs[0]) {
	printf("%i >= %i\n", taskPairs[2], taskPairs[0]);
	if (taskPairs[3] <= taskPairs[1]) {
	    printf("%i <= %i\n", taskPairs[3], taskPairs[1]);
	    puts("Found Redundancy");
	    return 1;
	} else {
	    printf("%i > %i\n", taskPairs[3], taskPairs[1]);
	    puts("No Redundancy");
	    return 0;
	}
    } else {
	printf("%i < %i\n", taskPairs[2], taskPairs[0]);
	if (taskPairs[3] >= taskPairs[1]) {
	    printf("%i >= %i\n", taskPairs[3], taskPairs[1]);
	    puts("Found Redundancy");
	    return 1;
	} else {
	    printf("%i < %i\n", taskPairs[3], taskPairs[1]);
	    puts("No Redundancy");
	    return 0;
	}
    }
}

int main(void) {
    FILE * tasks;
    char * line;
    size_t len = 0;
    ssize_t read;
    unsigned int taskNumbers;
    tasks = fopen("./input", "r");
    if (tasks == NULL) {
	puts("File Not Found");
	return 1;
    }

    int taskPairs[4];
    int redundancies = 0, i = 0;

    while ((read = getline(&line, &len, tasks)) != -1) {

	

	if (i == 4) {
	    redundancies += containsRedundancy(taskPairs);
	    i = 0;
	}
    }

    printf("Redundancies: %i\n", redundancies);

    fclose(tasks);

    return 0;
}
