/*
Solved!
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PATH "./input"
#define COLUMNS 99
#define ROWS 99

void dumpMatrix(int matrix[ROWS][COLUMNS]);
void checkVisibility(int treeMatrix[ROWS][COLUMNS],
		     int seenMatrix[ROWS][COLUMNS]);

int main(void) {
    FILE *treeMap;
    if ((treeMap = fopen(PATH, "r")) == NULL) {
	puts("File Not Found");
	exit(1);
    }

    char *line = NULL;
    int lineNum = 0;
    size_t len = 0;
    ssize_t read;

    int treeMatrix[ROWS][COLUMNS];
    int seenMatrix[ROWS][COLUMNS];
    int treesVisible = 0;

    while ((read = getline(&line, &len, treeMap)) != -1) {
	for (int i = 0; i < COLUMNS; i++) {
	    treeMatrix[lineNum][i] = (line[i] - '0');
	    seenMatrix[lineNum][i] = 0;
	}

	lineNum++;
    }

    checkVisibility(treeMatrix, seenMatrix);

    for (int i = 0; i < ROWS; i++) {
	for (int j = 0; j < COLUMNS; j++) {
	    treesVisible += seenMatrix[i][j];
	}
    }

    printf("Trees visible: %d\n", treesVisible);

    free(line);
    fclose(treeMap);
    return 0;
}

// check visibility
void checkVisibility(int treeMatrix[ROWS][COLUMNS],
		     int seenMatrix[ROWS][COLUMNS]) {
    int tallestSeen = -1;

    for (int i = 0; i < COLUMNS; i++) {
	for (int j = 0; j < ROWS; j++) {
	    if (treeMatrix[j][i] > tallestSeen) {
		tallestSeen = treeMatrix[j][i];
		seenMatrix[j][i] = 1;
	    }
	}

	tallestSeen = -1;
    }

    for (int i = COLUMNS - 1; i >= 0; i--) {
	for (int j = ROWS - 1; j >= 0; j--) {
	    if (treeMatrix[j][i] > tallestSeen) {
		tallestSeen = treeMatrix[j][i];
		seenMatrix[j][i] = 1;
	    }
	}

	tallestSeen = -1;
    }

    for (int i = 0; i < ROWS; i++) {
	for (int j = 0; j < COLUMNS; j++) {
	    if (treeMatrix[i][j] > tallestSeen) {
		tallestSeen = treeMatrix[i][j];
		seenMatrix[i][j] = 1;
	    }
	}

	tallestSeen = -1;
    }

    for (int i = ROWS - 1; i >= 0; i--) {
	for (int j = COLUMNS - 1; j >= 0; j--) {
	    if (treeMatrix[i][j] > tallestSeen) {
		tallestSeen = treeMatrix[i][j];
		seenMatrix[i][j] = 1;
	    }
	}

	tallestSeen = -1;
    }
}
