/*
Solved!
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isMessageStart(char charSet[14]) {
    if ((int)strlen(charSet) != 14) {
	return false;
    }

    for (int i = 0; i < 13; i++) {
	for (int j = (i + 1); j < 14; j++) {
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
    char testStr[14];
    int charsProcessed = 0;

    packet = fopen("./input", "r");
    if (packet == NULL) {
	puts("File Not Found");
	return 1;
    }

    while ((ch = fgetc(packet)) != EOF) {
	charsProcessed++;

	for (int i = 13; i > 0; i--) {
	    testStr[i] = testStr[i - 1];
	}

	testStr[0] = ch;

	if (isMessageStart(testStr)) break;
    }

    printf("Characters Processed: %i\n", charsProcessed);

    return 0;
}
