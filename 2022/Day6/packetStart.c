/*
Solved!
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPacketStart(char charSet[4]) {
    if ((int)strlen(charSet) != 4) {
	return false;
    }

    for (int i = 0; i < 3; i++) {
	for (int j = (i + 1); j < 4; j++) {
	    if (charSet[i] == charSet[j]) {
		return false;
	    }
	}
    }

    return true;
}

int main(void) {
    FILE * packet;
    char ch;
    char testStr[4];
    int charsProcessed = 0;

    packet = fopen("./input", "r");
    if (packet == NULL) {
	puts("File Not Found");
	return 1;
    }

    while ((ch = fgetc(packet)) != EOF) {
	charsProcessed++;

	for (int i = 3; i > 0; i--) {
	    testStr[i] = testStr[i - 1];
	}

	testStr[0] = ch;

	if (isPacketStart(testStr)) break;
    }

    printf("Characters Processed: %i\n", charsProcessed);

    return 0;
}
