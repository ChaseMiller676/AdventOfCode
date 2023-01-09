/*
Solved!
*/
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 56

int topOne = -1, topTwo = -1, topThree = -1,
    topFour = -1, topFive = -1, topSix = -1,
    topSeven = -1, topEight = -1, topNine = -1;
char stackOne[SIZE], stackTwo[SIZE], stackThree[SIZE],
    stackFour[SIZE], stackFive[SIZE], stackSix[SIZE],
    stackSeven[SIZE], stackEight[SIZE], stackNine[SIZE];

void push(int stack, char crate) {
    switch (stack) {
    case 0:
	if (topOne == (SIZE - 1)) {
	    puts("Stack Overflow");
	    exit(1);
	}

	topOne++;
	stackOne[topOne] = crate;
	break;
    case 1:
	if (topTwo == (SIZE - 1)) {
	    puts("Stack Overflow");
	    exit(1);
	}
	
	topTwo++;
	stackTwo[topTwo] = crate;
	break;
    case 2:
	if (topThree == (SIZE - 1)) {
	    puts("Stack Overflow");
	    exit(1);
	}

	topThree++;
	stackThree[topThree] = crate;
	break;
    case 3:
	if (topFour == (SIZE - 1)) {
	    puts("Stack Overflow");
	    exit(1);
	}

	topFour++;
	stackFour[topFour] = crate;
	break;
    case 4:
	if (topFive == (SIZE - 1)) {
	    puts("Stack Overflow");
	    exit(1);
	}
	
	topFive++;
	stackFive[topFive] = crate;
	break;
    case 5:
	if (topSix == (SIZE - 1)) {
	    puts("Stack Overflow");
	    exit(1);
	}

	topSix++;
	stackSix[topSix] = crate;
	break;
    case 6:
	if (topSeven == (SIZE - 1)) {
	    puts("Stack Overflow");
	    exit(1);
	}

	topSeven++;
	stackSeven[topSeven] = crate;
	break;
    case 7:
	if (topEight == (SIZE - 1)) {
	    puts("Stack Overflow");
	    exit(1);
	}
	
	topEight++;
	stackEight[topEight] = crate;
	break;
    case 8:
	if (topNine == (SIZE - 1)) {
	    puts("Stack Overflow");
	    exit(1);
	}

	topNine++;
	stackNine[topNine] = crate;
	break;
    }
}

void pop(int stack) {
    switch (stack) {
    case 0:
	if (!(topOne >= 0)) {
	    puts("Stack Underflow");
	    exit(1);
	}
	topOne--;
	break;
    case 1:
	if (!(topTwo >= 0)) {
	    puts("Stack Underflow");
	    exit(1);
	}
	topTwo--;
	break;
    case 2:
	if (!(topThree >= 0)) {
	    puts("Stack Underflow");
	    exit(1);
	}
	topThree--;
	break;
    case 3:
	if (!(topFour >= 0)) {
	    puts("Stack Underflow");
	    exit(1);
	}
	topFour--;
	break;
    case 4:
	if (!(topFive >= 0)) {
	    puts("Stack Underflow");
	    exit(1);
	}
	topFive--;
	break;
    case 5:
	if (!(topSix >= 0)) {
	    puts("Stack Underflow");
	    exit(1);
	}
	topSix--;
	break;
    case 6:
	if (!(topSeven >= 0)) {
	    puts("Stack Underflow");
	    exit(1);
	}
	topSeven--;
	break;
    case 7:
	if (!(topEight >= 0)) {
	    puts("Stack Underflow");
	    exit(1);
	}
	topEight--;
	break;
    case 8:
	if (!(topNine >= 0)) {
	    puts("Stack Underflow");
	    exit(1);
	}
	topNine--;
    }
}

void show(int stack) {
    switch (stack) {
    case 0:
	if (!(topOne >= 0)) {
	    puts("Empty Stack");
	    break;
	}

	for (int i = topOne; i >= 0; i--) {
	    printf("%c", stackOne[i]);
	}
	putchar('\n');
	break;
    case 1:
	if (!(topTwo >= 0)) {
	    puts("Empty Stack");
	    break;
	}
	
	for (int i = topTwo; i >= 0; i--) {
	    printf("%c", stackTwo[i]);
	}
	putchar('\n');
	break;
    case 2:	
	if (!(topThree >= 0)) {
	    puts("Empty Stack");
	    break;
	}

	for (int i = topThree; i >= 0; i--) {
	    printf("%c", stackThree[i]);
	}
	putchar('\n');
	break;
    case 3:
	if (!(topFour >= 0)) {
	    puts("Empty Stack");
	    break;
	}

	for (int i = topFour; i >= 0; i--) {
	    printf("%c", stackFour[i]);
	}
	putchar('\n');
	break;
    case 4:
	if (!(topFive >= 0)) {
	    puts("Empty Stack");
	    break;
	}

	for (int i = topFive; i >= 0; i--) {
	    printf("%c", stackFive[i]);
	}
	putchar('\n');
	break;
    case 5:	
	if (!(topSix >= 0)) {
	    puts("Empty Stack");
	    break;
	}

	for (int i = topSix; i >= 0; i--) {
	    printf("%c", stackSix[i]);
	}
	putchar('\n');
	break;
    case 6:
	if (!(topSeven >= 0)) {
	    puts("Empty Stack");
	    break;
	}

	for (int i = topSeven; i >= 0; i--) {
	    printf("%c", stackSeven[i]);
	}
	putchar('\n');
	break;
    case 7:
	if (!(topEight >= 0)) {
	    puts("Empty Stack");
	    break;
	}

	for (int i = topEight; i >= 0; i--) {
	    printf("%c", stackEight[i]);
	}
	putchar('\n');
	break;
    case 8:
	if (!(topNine >= 0)) {
	    puts("Empty Stack");
	    break;
	}

	for (int i = topNine; i >= 0; i--) {
	    printf("%c", stackNine[i]);
	}
	putchar('\n');
    }

}

void initStacks() {
    char * columns[9] = {
	"MSJLVFNR",
	"HWJFZDNP",
	"GDCRW",
	"SBN",
	"NFBCPWZM",
	"WMRP",
	"WSLGNTR",
	"VBNFHTQ",
	"FNZHML"
    };

    for (int i = 0; i < 9; i++) {
	for (int j = (int)(strlen(columns[i]) - 1); j >= 0; j--) {
	    push(i, columns[i][j]);
	}
    }
}

void moveCrates(int cratesToMove, int srcStack, int destStack) {
    switch (srcStack) {
    case 1:
	for (int i = 0; i < cratesToMove; i++){
	    push(destStack - 1, stackOne[topOne]);
	    pop(srcStack - 1);
	}
	break;
    case 2:
	for (int i = 0; i < cratesToMove; i++){
	    push(destStack - 1, stackTwo[topTwo]);
	    pop(srcStack - 1);
	}
	break;
    case 3:
	for (int i = 0; i < cratesToMove; i++){
	    push(destStack - 1, stackThree[topThree]);
	    pop(srcStack - 1);
	}
	break;
    case 4:
	for (int i = 0; i < cratesToMove; i++){
	    push(destStack - 1, stackFour[topFour]);
	    pop(srcStack - 1);
	}
	break;
    case 5:
	for (int i = 0; i < cratesToMove; i++){
	    push(destStack - 1, stackFive[topFive]);
	    pop(srcStack - 1);
	}
	break;
    case 6:
	for (int i = 0; i < cratesToMove; i++){
	    push(destStack - 1, stackSix[topSix]);
	    pop(srcStack - 1);
	}
	break;
    case 7:
	for (int i = 0; i < cratesToMove; i++){
	    push(destStack - 1, stackSeven[topSeven]);
	    pop(srcStack - 1);
	}
	break;
    case 8:
	for (int i = 0; i < cratesToMove; i++){
	    push(destStack - 1, stackEight[topEight]);
	    pop(srcStack - 1);
	}
	break;
    case 9:
	for (int i = 0; i < cratesToMove; i++){
	    push(destStack - 1, stackNine[topNine]);
	    pop(srcStack - 1);
	}
    }
}

int main(void) {

    FILE * instructions;
    char * line = NULL;
    size_t len = 0;
    int cratesToMove, srcStack, destStack;
    int * pInstructVals[3] = {
	&cratesToMove,
	&srcStack,
	&destStack
    };

    instructions = fopen("./input", "r");
    if (instructions == NULL) {
	puts("File Not Found");
	return 1;
    }

    initStacks();

    while (getline(&line, &len, instructions) != -1) {
	for (int i = 0; i < (int)strlen(line); i++) {
	    if (!((int)line[i] >= 48 && (int)line[i] <= 57)) {
		line[i] = ' ';
	    }
	}

	int i = 0;
	char *start = line;
	char *eon;
	long value;
	errno = 0;

	while ((value = strtol(start, &eon, 0)),
	       eon != start &&
	       !((errno == EINVAL && value == 0) ||
		 (errno == ERANGE && (value == LONG_MIN || value == LONG_MAX)))) {
	    
	    *pInstructVals[i] = value;
	    i++;
	    start = eon;
	    errno = 0;
	}
	moveCrates(cratesToMove, srcStack, destStack);   
    }

    for (int i = 0; i < 9; i++) {
	show(i);
    }
    return 0;
}
