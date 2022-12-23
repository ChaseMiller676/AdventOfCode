#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int calcCharPriority(char character) {
    if ((int)character == 0 && character != '0') {
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
	seen[i] = '0';
    }

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

    for (int i = 0; i < (int)len; i++) {
	if (seen[i] == '0') {
	    break;
	}
	priority += calcCharPriority(seen[i]);
    }

    return priority;
}

int main(void) {
    FILE * pRucksack;
    char * line;
    int j, k, priority = 0;
    size_t len = 0;
    ssize_t read;

    pRucksack = fopen("./input", "r");
    if (pRucksack == NULL) {
	puts("File Not Found");
	return 1;
    }

    while ((read = getline(&line, &len, pRucksack)) != -1) { 
	size_t lineLen = strlen(line) - 1;
	size_t halfLineLen = lineLen/2;
	char compOne[halfLineLen], compTwo[halfLineLen];

	for (j = 0; (unsigned long)j < halfLineLen; j++) {
	    compOne[j] = line[j];
	}

	for (k = 0; (unsigned long)k < halfLineLen; k++) {
	    compTwo[k] = line[halfLineLen+k];
	}

	priority += calcSackPriority(compOne, compTwo, halfLineLen);
    }

     fclose(pRucksack);
     if (line) { 
	 free(line);
     }

    printf("Total Priority: %i\n", priority);

    return 0;
}
