/*
Solved!
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

// review this function and find out why it works
int calculateScenicScore(int treeMatrix[ROWS][COLUMNS], int row, int column) {
    int threshold = treeMatrix[row][column];
    int dx=0;
    int dy=0;
    int scenicScore = 1;

    for(dy=row-1;dy>=0;dy--) {
        if(treeMatrix[dy][column] >= threshold || dy==0) {
            scenicScore *= (row - dy);
            break;
        }
    }

    for(dy=row+1;dy<ROWS;dy++) {
        if(treeMatrix[dy][column] >= threshold || dy == ROWS-1) {
            scenicScore *= (dy-row);
            break;
        }
    }

    for(dx=column-1;dx>=0;dx--) {
        if(treeMatrix[row][dx] >= threshold || dx == 0) {
            scenicScore *= (column-dx);
            break;
        }
    }

    for(dx=column+1;dx<COLUMNS;dx++) {
        if(treeMatrix[row][dx] >= threshold || dx == COLUMNS-1) {
            scenicScore *= (dx - column);
            break;
        }
    }
    return scenicScore;
}
