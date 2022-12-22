/*
Solved!
*/
#include <stdio.h>

int simulateMatch(char elfMove, char desiredOutcome) {
    switch(elfMove) {
    case 'A':
	switch(desiredOutcome) {
	case 'X': return 3;
	case 'Y': return 4;
	case 'Z': return 8;
	}
	break;
    case 'B':
	switch(desiredOutcome) {
	case 'X': return 1;
	case 'Y': return 5;
	case 'Z': return 9; 
	}
	break;
    case 'C':
	switch(desiredOutcome) {
	case 'X': return 2;
	case 'Y': return 6;
	case 'Z': return 7;
	}
	break;
    }

    return -1;
}

int main(void) {
    FILE * pMoveList;
    char ch;
    pMoveList = fopen("./input", "r");

    if (pMoveList == NULL) {
	puts("File Not Found");
	return 1;
    }

    char elfMove, desiredOutcome;
    int score = 0;
    int i = 0;

    do {
	ch = fgetc(pMoveList);
	if (ch != ' ' && ch != '\n') {
	    switch(i % 2) {
	    case 0:
		elfMove = ch;
		i++;
		break;
	    case 1:
		desiredOutcome = ch;
		score += simulateMatch(elfMove, desiredOutcome);
		i++;
		break;
	    }
	}
    } while(ch != EOF);

    printf("Final Score: %i\n", score);

    return 0;
}
