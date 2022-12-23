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
	    return ((int)character - 38);
	}
    }
}

int calcSackPriority(char * stringOne, char * stringTwo, size_t len) {
    int seenIndex = 0, priority = 0;
    bool flag;
    char seen[len];

    for (int i = 0; i < (int)len; i++) {
	flag = false;
	for (int j = 0; j < (int)len; j++) {
	    if (stringOne[i] == seen[j]) {
		flag = true;
		break;
	    }
	}
	
	if (!flag) {
	    for (int j = 0; j < (int)len; j++) {
		if (stringOne[i] == stringTwo[j]) {
		    seen[seenIndex] = stringOne[i];
		    seenIndex++;
		    break;
		}
	    }
	}
    }

    for (; seenIndex < (int)len; seenIndex++) {
	seen[seenIndex] = '0';
    }

    for (int i = 0; i < (int)len; i++) {
	if (seen[i] == '0') {
	    break;
	}
	priority += calcCharPriority(seen[i]);
    }

    printf("%i\n", priority);
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
	char compOne[halfLen], compTwo[halfLen];

	for (j = 0; (unsigned long)j < halfLen; j++) {
	    compOne[j] = sacks[i][j];
	}

	for (k = 0; (unsigned long)k < halfLen; k++) {
	    compTwo[k] = sacks[i][halfLen+k];
	}

	priority += calcSackPriority(compOne, compTwo, halfLen);
    }

    printf("Total Priority: %i\n", priority);

    return 0;
}
