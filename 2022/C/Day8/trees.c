#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PATH "./testInput"

char **grid;

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


    while ((read = getline(&line, &len, treeMap)) != -1) {
	for (int i = 0; i < (int)len; i++) {
	    grid[lineNum][i] = line[i];
	}

	lineNum++;
    }

    for (unsigned int i = 0; i < strlen(grid[0]); i++) {
	for (int j = 0; j < lineNum; j++) {
	    printf("%c", grid[i][j]);
	}
    }

    return 0;
}
