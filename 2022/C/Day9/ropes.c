#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define INPUT "./testInput"
#define ROWS 5
#define COLUMNS 6

void moveHead(int headPos[2], char travelDirection);
void moveTail(const int headPos[2], int tailPos[2]);
void dumpMap(char map[ROWS][COLUMNS]);

int main(void) {
    FILE *input;
    if ((input = fopen(INPUT, "r")) == NULL) {
	puts("File Not Found");
	exit(1);
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    bool wasVisited[ROWS][COLUMNS];
    char visitedMap[ROWS][COLUMNS];
    int headPosition[2] = {ROWS - 1, 0};
    int tailPosition[2] = {ROWS - 1, 0};
    int positionsVisited = 0;
    char travelDirection;
    int steps = 0;

    for (int i = 0; i < ROWS; i++) {
	for (int j = 0; j < COLUMNS; j++) {
	    wasVisited[i][j] = false;
	}
    }
    puts("Row\tColumn");
    printf("%d\t%d\n", tailPosition[0], tailPosition[1]);
    while ((read = getline(&line, &len, input)) != -1) {
	wasVisited[headPosition[0]][headPosition[1]] = true;
	if (line != NULL){
	    travelDirection = line[0];
	    steps = line[2] - '0';
	}
	for (int i = 0; i < steps; i++) {
	    moveHead(headPosition, travelDirection);
	    moveTail(headPosition, tailPosition);
	    wasVisited[tailPosition[0]][tailPosition[1]] = true;
	    printf("%d\t%d\n", tailPosition[0], tailPosition[1]);
	}
    }

    free(line);
    fclose(input);

    for (int i = 0; i < ROWS; i++) {
	for (int j = 0; j < COLUMNS; j++) {
	    if (wasVisited[i][j] == true) {
		positionsVisited++;
	    }

	    visitedMap[i][j] = (wasVisited[i][j] == true)
		? '#'
		: '.';
	}
    }

    dumpMap(visitedMap);
    printf("Total Positions Visited: %d\n", positionsVisited);

    return 0;
}

void dumpMap(char map[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
	for (int j = 0; j < COLUMNS; j++) {
	    printf("%c", map[i][j]);
	}
	putchar('\n');
    }
}

void moveTail(const int headPos[2], int tailPos[2]) {
    int diffArray[2] = {
	headPos[0] - tailPos[0],
	headPos[1] - tailPos[1]
    };

    if (diffArray[0] == 2 && diffArray[1] == 0) {
	tailPos[0]++;
	return;
    }

    if (diffArray[1] == 2 && diffArray[0] == 0) {
	tailPos[1]++;
	return;
    }

    if (diffArray[0] == -2 && diffArray[1] == 0) {
	tailPos[0]--;
	return;
    }

    if (diffArray[1] == -2 && diffArray[0] == 0) {
	tailPos[1]--;
	return;
    }

    if ((diffArray[0] == 2 && diffArray[1] == 1)
	|| (diffArray[1] == 2 && diffArray[0] == 1)
	|| (diffArray[0] == 2 && diffArray[1] == 2)) {
	tailPos[0]++;
	tailPos[1]++;
	return;
    }

    if ((diffArray[0] == -2 && diffArray[1] == -1)
	|| (diffArray[1] == -2 && diffArray[0] == -1)
	|| (diffArray[0] == -2 && diffArray[1] == -2)) {
	tailPos[0]--;
	tailPos[1]--;
	return;
    }

    if ((diffArray[0] == -2 && diffArray[1] == 1)
	|| (diffArray[1] == 2 && diffArray[0] == -1)
	|| (diffArray[0] == -2 && diffArray[1] == 2)) {
	tailPos[0]--;
	tailPos[1]++;
	return;
    }

    if ((diffArray[0] == 2 && diffArray[1] == -1)
	|| (diffArray[1] == -2 && diffArray[0] == +1)
	|| (diffArray[0] == 2 && diffArray[1] == -2)) {
	tailPos[0]++;
	tailPos[1]--;
	return;
    }
}

void moveHead(int headPos[2], char travelDirection) {
    switch (travelDirection) {
    case 'U':
	headPos[0]--;
	break;
    case 'D':
	headPos[0]++;
	break;
    case 'L':
	headPos[1]--;
	break;
    case 'R':
	headPos[1]++;
	break;
    }

    if (headPos[0] < 0 || headPos[0] >= ROWS ||
	headPos[1] < 0 || headPos[1] >= COLUMNS) {
	puts("Out of bounds error");
	exit(1);
    }    
}
