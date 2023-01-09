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
    int finalSums[3] = {0, 0, 0};

    pInventory = fopen("./input", "r");
    if (pInventory == NULL) {
	puts("File Not Found");
	return 1;
    }

    while ((read = getline(&line, &len, pInventory)) != -1) {
	if (strlen(line) == 1) {
	    if (tempSum > finalSums[0]) {
		finalSums[0] += tempSum - finalSums[0];
	    }
	    if (tempSum > finalSums[1]) {
		finalSums[0] = finalSums[1];
		finalSums[1] += tempSum - finalSums[1];
	    }
	    if (tempSum > finalSums[2]) {
		finalSums[1] = finalSums[2];
		finalSums[2] += tempSum - finalSums[2];
	    }

	    tempSum = 0;
	} else {
	    tempSum += stringToInt(line);	    
	}
    }

    fclose(pInventory);
    if (line) {
	free(line);
    }

    printf("First:\t%i\n", finalSums[2]);
    printf("Second:\t%i\n", finalSums[1]);
    printf("Third:\t%i\n", finalSums[0]);
    printf("Sum: %i\n", (finalSums[0] + finalSums[1] + finalSums[2]));

    return 0;

}
