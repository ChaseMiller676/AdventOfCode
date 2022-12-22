#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t calcCharPriority(char ch) {
    size_t priority = 0;

    if ((int)ch > 96) {
	priority -= 96;
    } else {
	priority -= 38;
    }

    return priority;
}

size_t calcLinePriority(size_t len, char line[len]) {
    size_t priority = 0;

    for (size_t i = 0; i < len/2; i++) {
	if (line[i] == line[i + len/2]) {
	    priority += calcCharPriority(line[i]);
	}
    }

    return priority;
}

int main(void) {
    /* FILE * pRucksack; */
    char * line[6] = {
	"vJrwpWtwJgWrhcsFMMfFFhFp\0",
	"jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL\0",
	"PmmdzqPrVvPwwTWBwg\0",
	"wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn\0",
	"ttgJtRGJQctTZtZT\0",
	"CrZsJsPPZsGzwwsLwLmpwMDw\0"
    };
    size_t totalPriority = 0;
    size_t len;
    /* ssize_t read;

    pRucksack = fopen("./input", "r");
    if (pRucksack == NULL) {
	puts("File Not Found");
	return 1;
    }

    while ((read = getline(&line, &len, pRucksack)) != -1) { 
     	totalPriority += calcLinePriority(line, len);
     }

     fclose(pRucksack);
     if (line) { 
	 free(line);
     } */

    for (int i = 0; i < 6; i++) {
	len = strlen(line[i]);
	totalPriority += calcLinePriority(len, *line);
    }

    printf("Total Priority: %lu\n", totalPriority);

    return 0;
}
