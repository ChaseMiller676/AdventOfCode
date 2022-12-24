#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, stdin) != -1)
    {
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
