/*
Solved!
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stringToInt(char * string) {
    int result = 0;

    for (int i = 0; i < (int)(strlen(string) - 1); i++) {
	result = result * 10 + ( string[i] - '0');
    }

    return result;
}

int main(void) {
    FILE * pInventory;
    char * line;
    size_t len = 0;
    ssize_t read;

    int tempSum = 0;
    int finalSum = 0;

    pInventory = fopen("./input", "r");
    if (pInventory == NULL) {
	puts("File Not Found");
	return 1;
    }

    while ((read = getline(&line, &len, pInventory)) != -1) {
	if (strlen(line) == 1) {
	    if (tempSum > finalSum) {
		finalSum = tempSum;
	    }

	    tempSum = 0;
	} else {
	    tempSum += stringToInt(line);	    
	}
    }

    printf("Most Calories: %i\n", finalSum);

    fclose(pInventory);
    if (line) {
	free(line);
    }

    return 0;
}
