#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_PATH "./testInput"

enum {
    LOG_MODE,
    CD_MODE
};

typedef struct dir {
    char *dirName;
    unsigned int fileSizes[1000];
    struct dir *subDir[1000];
    struct dir *parent;
} dir;

dir *currentNode;
int currentSDcount = 0;
int currentFileCount = 0;

char *getSubString(char *string, int subStart, int subEnd);
dir *newDir(dir *parent, char *dirName);
void logData(char *line);

void changeDir(char *command) {
    char *destDir = getSubString(command, 5, strlen(command) - 1);
    // This causes a seg fault when the parent is NULL
    // shouldn't be a problem after the function is completed
    if (strcmp(destDir, "..") == 0 && currentNode->parent != NULL) {
	currentNode = currentNode->parent;
	return;
    }

    // 
}

int main(void) {
    FILE *commandLog;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int mode;

    if ((commandLog = fopen(FILE_PATH, "r")) == NULL) {
	puts("File Not Found");
	exit(1);
    }

    currentNode = newDir(NULL, "/");

    while ((read = getline(&line, &len, commandLog)) != -1) {
	if (line[0] == '$') {
	    switch (line[2]) {
	    case 'l':
		mode = LOG_MODE;
		continue;
	    case 'c':
		mode = CD_MODE;
		break;
	    }
	}

	switch (mode) {
	case LOG_MODE:
	    logData(line);
	    break;
	case CD_MODE:
	    changeDir(line);
	    break;
	default:
	    puts("ERROR");
	    exit(1);
	}
    }

    return 0;
}

char *getSubString(char *string, int subStart, int subEnd) {
    int subLen = (subEnd - subStart);
    char *subString = malloc(subLen);

    for (int i = 0; i < subLen; i++) {
	subString[i] = string[i + subStart];
    }

    return subString;
}

dir *newDir(dir *parent, char *dirName) {
    dir *node = malloc(sizeof(dir));
    node->dirName = dirName;
    node->parent = parent;
    return node;
}

void logData(char *line) {
    if (line[0] != 'd') {
	unsigned int fileSize;
	sscanf(line, "%u", &fileSize);
	currentNode->fileSizes[currentFileCount] = fileSize;
	currentFileCount++;
	return;
    }
    
    char *dirName = getSubString(line, 4, strlen(line) - 1);
    currentNode->subDir[currentSDcount] = newDir(currentNode, dirName);
    currentSDcount++;
}
