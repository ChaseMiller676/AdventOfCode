/*
 Solved!
*/
#include <stdio.h>

int calculatePoints(char playerMove, char elfMove) {
    switch(playerMove) {
    case 'X':
	switch(elfMove) {
	case 'A': return 4;
	case 'B': return 1;
	case 'C': return 7;
	}
	break;
    case 'Y':
	switch(elfMove) {
	case 'A': return 8;
	case 'B': return 5;
	case 'C': return 2;
	}
	break;
    case 'Z':
    	switch(elfMove) {
	case 'A': return 3;
	case 'B': return 9;
	case 'C': return 6;
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

    char playerMove, elfMove;
    int score = 0;
    int i = 1;

    do {
	ch = fgetc(pMoveList);
	if (ch != ' ' && ch != '\n') {
	    switch(i % 2) {
	    case 0:
		playerMove = ch;
		score += calculatePoints(playerMove, elfMove);
		i++;
		break;
	    default:
		elfMove = ch;
		i++;
	    }
	}
    } while(ch != EOF);

    printf("Final Score: %i\n", score);

    return 0;
}
