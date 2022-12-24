#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE * testFile;
    testFile = fopen("./input", "r");

    if (testFile == NULL) {
	puts("File Not Found");
	return 1;
    }

    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, testFile) != -1)
    {
	for (int i = 0; i < (int)strlen(line); i++) {
	    if (line[i] == ',' || line[i] == '-') {
		line[i] = ' ';
	    }
	}
	
        printf("Line input : [%s]\n", line);
        int val = atoi(line);
        printf("Parsed integer: %d\n", val);

        char *start = line;
        char *eon;
        long value;
        errno = 0;
        while ((value = strtol(start, &eon, 0)),
	       eon != start &&
               !((errno == EINVAL && value == 0) ||
                 (errno == ERANGE && (value == LONG_MIN || value == LONG_MAX))))
        {
            printf("%ld\n", value);
            start = eon;
            errno = 0;
        }
        putchar('\n');
    }
    free(line);
    return 0;
}
