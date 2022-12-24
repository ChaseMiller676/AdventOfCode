#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int calcCharPriority(char character) {
    if ((int)character == 0 && character != '0') {
	return 0;
    } else {
	if ((int)character > 96) {
	    return ((int)character - 96);
	} else {
	    return ((int)character - 38);
	}
    }
}

int calcGroupPriority(char group[3][50]) {
    bool firstMatchFlag = false, secondMatchFlag = false;

    for (int i = 0; i < (int)sizeof(group[0]); i++) {
	for (int j = 0; j < (int)sizeof(group[1]); j++) {
	    if (group[1][j] == group[0][i]) {
		firstMatchFlag = true;
		break;
	    }
	}

	if (firstMatchFlag) {
	    for (int k = 0; k < (int)sizeof(group[2]); k++) {
		if (group[2][k] == group[0][i]) {
		    secondMatchFlag = true;
		    break;
		}
	    }
	}

	if (secondMatchFlag) {
	    return calcCharPriority(group[0][i]);
	} else {
	    firstMatchFlag = false;
	}
    }

    return 0;
}

int main(void) {
    FILE * pRucksack;
    char * line;
    char group[3][50];
    int i = 0, j = 1, priority = 0;
    size_t len = 0;
    ssize_t read;

    pRucksack = fopen("./input", "r");
    if (pRucksack == NULL) {
	puts("File Not Found");
	return 1;
    }

    while ((read = getline(&line, &len, pRucksack)) != -1) { 
	strcpy(group[i], line);
	i = (i + 1) % 3;
	if (i == 0) {
	    printf("Group %i:\n", j);
	    for (int k = 0; k < 3; k++) {
		printf("%s", group[k]);
	    }
	    j++;
	    priority += calcGroupPriority(group);
	    printf("Priority: %i\n", priority);	    
	}
    }

    fclose(pRucksack);
    if (line) { 
	free(line);
    }

    return 0;
}
