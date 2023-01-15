/*
Solved!
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_PATH "./input"
#define FILESYSTEM_SIZE 70000000

enum {
    LOG_MODE,
    CD_MODE
};

typedef struct dir {
    char *dirName;
    int subDirCount;
    int size;
    struct dir *subDir[100];
    struct dir *parent;
} dir;

dir *currentNode;
int targetDirSize = FILESYSTEM_SIZE;

// This assumes that the filesystem is empty
// Should change after running initFileSystem()
int availableSpace = FILESYSTEM_SIZE;
int neededSpace;

char *getSubString(char *string, int subStart, int subEnd);
dir *newDir(dir *parent, char *dirName);
void logData(char *line);
void changeDir(char *command);
void initFileSystem();
void parseNode(dir *node);
void correctDirSizes(dir *node);

int main(void) {
    initFileSystem();
    availableSpace -= currentNode->size;
    neededSpace = 30000000 - availableSpace;
    parseNode(currentNode);

    printf("Target Directory Size: %d\n", targetDirSize);
    
    return 0;
}

// Parsing

void parseNode(dir *node) {
    if (node->size >= neededSpace && node->size <= targetDirSize) {
	targetDirSize = node->size;
    }

    for (int i = 0; i < node->subDirCount; i++) {
	parseNode(node->subDir[i]);
    }
}

// Initialization

void initFileSystem() {
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

    fclose(commandLog);
    commandLog = NULL;
    free(line);
    line = NULL;

    while (currentNode->parent != NULL &&
	   strcmp(currentNode->dirName, "/") != 0) {
	currentNode = currentNode->parent;
    }

    correctDirSizes(currentNode);

    while (currentNode->parent != NULL &&
	   strcmp(currentNode->dirName, "/") != 0) {
	currentNode = currentNode->parent;
    }    
}

void correctDirSizes(dir *node) {
    for (int i = 0; i < node->subDirCount; i++) {
	if (node->subDir[i]->subDirCount != 0){
	    correctDirSizes(node->subDir[i]);
	}
	node->size += node->subDir[i]->size;
    }
}

void logData(char *line) {
    if (line[0] != 'd') {
	unsigned int fileSize;
	sscanf(line, "%u", &fileSize);
	currentNode->size += fileSize;
	return;
    }
    
    char *dirName = getSubString(line, 4, strlen(line) - 1);
    currentNode->subDir[currentNode->subDirCount]
	= newDir(currentNode, dirName);
    currentNode->subDirCount++;
}

dir *newDir(dir *parent, char *dirName) {
    dir *node = malloc(sizeof(dir));
    node->dirName = dirName;
    node->parent = parent;
    node->subDirCount = 0;
    node->size = 0;
    return node;
}

// General Use

char *getSubString(char *string, int subStart, int subEnd) {
    int subLen = (subEnd - subStart);
    char *subString = malloc(subLen);

    for (int i = 0; i < subLen; i++) {
	subString[i] = string[i + subStart];
    }

    return subString;
}

void changeDir(char *command) {
    char *destDir = getSubString(command, 5, strlen(command) - 1);

    if (strcmp(destDir, "..") == 0 && currentNode->parent != NULL) {
	currentNode = currentNode->parent;
	return;
    }

    for (int i = 0; i < currentNode->subDirCount; i++) {
	if (strcmp(destDir, currentNode->subDir[i]->dirName) == 0) {
	    currentNode = currentNode->subDir[i];
	    break;
	}
    }
}
