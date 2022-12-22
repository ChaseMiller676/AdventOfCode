#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int calcCharPriority(char character) {
    if ((int)character == 0) {
	return 0;
    } else {
	if ((int)character > 96) {
	    return ((int)character - 96);
	} else {
	    return ((int)character - 64);
	}
    }
}

int calcSackPriority(char * stringOne, char * stringTwo, size_t len) {
    int charOneCount, charTwoCount, priority = 0;

    for (int i = 0; (unsigned long)i < len; i++) {
	for (int j = 0; (unsigned long)j < len; j++) {
	    if (stringOne[i] == stringTwo[j]) {
		
	    }
	}

	for (int j = 0; (unsigned long)j < len; j++) {
	    if (stringTwo[i] == stringOne[j]) {

	    }
	}

	
    }

    return priority;
}

int main(void) {
    int j, k, priority = 0;
    char * sacks[6] = {
	"vJrwpWtwJgWrhcsFMMfFFhFp",
	"jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL",
	"PmmdzqPrVvPwwTWBwg",
	"wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn",
	"ttgJtRGJQctTZtZT",
	"CrZsJsPPZsGzwwsLwLmpwMDw"
    };

    for (int i = 0; i < 6; i++) {
	size_t len = strlen(sacks[i]); 
	size_t halfLen = len/2;
	char compOne[halfLen+1], compTwo[halfLen+1];

	for (j = 0; (unsigned long)j < halfLen; j++) {
	    compOne[j] = sacks[i][j];
	}
	compOne[j] = '\0';

	for (k = 0; (unsigned long)k < halfLen; k++) {
	    compTwo[k] = sacks[i][halfLen+k];
	}
	compTwo[k] = '\0';

	priority += calcSackPriority(compOne, compTwo, halfLen);
    }

    printf("Total Priority: %i\n", priority);

    return 0;
}
