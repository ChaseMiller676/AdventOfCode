/*
TODO: Fix the algorithm so that I get the correct answer
instead of a wrong answer
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PATH "./input"
#define COLUMNS 99
#define ROWS 99

enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

void dumpMatrix(int matrix[ROWS][COLUMNS]);
int calculateScenicScore(int treeMatrix[ROWS][COLUMNS], int row, int column);

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
    int testingScore = 0;
    int highestScore = 0;

    while ((read = getline(&line, &len, treeMap)) != -1) {
	for (int i = 0; i < COLUMNS; i++) {
	    treeMatrix[lineNum][i] = (line[i] - '0');
	}

	lineNum++;
    }

    free(line);
    fclose(treeMap);

    for (int i = 1; i < (ROWS - 1); i++) {
	for (int j = 1; j < (COLUMNS - 1); j++) {
	    testingScore = calculateScenicScore(treeMatrix, i, j);
	    printf("Testing Score: %d\n", testingScore);
	    if (highestScore < testingScore) {
		highestScore = testingScore;
	    }

	    testingScore = 0;
	}
    }

    printf("Highest Score: %d\n", highestScore);

    return 0;
}

int calculateScenicScore(int treeMatrix[ROWS][COLUMNS], int row, int column) {
    int blockerTreeHeight = -1;
    int visibleTrees[4] = {0, 0, 0, 0};

    for (int i = (row - 1); i >= 0; i--) {
	if (treeMatrix[i][column] >= blockerTreeHeight) {
	    blockerTreeHeight = treeMatrix[i][column];
	    visibleTrees[UP]++;
	}

	if (blockerTreeHeight >= treeMatrix[row][column]) {
	    break;
	}
    }

    blockerTreeHeight = -1;

    for (int i = (row + 1); i < ROWS; i++) {
	if (treeMatrix[i][column] >= blockerTreeHeight) {
	    blockerTreeHeight = treeMatrix[i][column];
	    visibleTrees[DOWN]++;
	}

	if (blockerTreeHeight >= treeMatrix[row][column]) {
	    break;
	}
    }

    blockerTreeHeight = -1;

    for (int i = (column - 1); i >= 0; i--) {
	if (treeMatrix[row][i] >= blockerTreeHeight) {
	    blockerTreeHeight = treeMatrix[row][i];
	    visibleTrees[LEFT]++;
	}

	if (blockerTreeHeight >= treeMatrix[row][column]) {
	    break;
	}
    }
    
    blockerTreeHeight = -1;


    for (int i = column + 1; i < COLUMNS; i++) {
	if (treeMatrix[row][i] >= blockerTreeHeight) {
	    blockerTreeHeight = treeMatrix[row][i];
	    visibleTrees[RIGHT]++;
	}

	if (blockerTreeHeight >= treeMatrix[row][column]) {
	    break;
	}
    }

    return (visibleTrees[UP] * visibleTrees[DOWN] *
	    visibleTrees[LEFT] * visibleTrees[RIGHT]);
}
