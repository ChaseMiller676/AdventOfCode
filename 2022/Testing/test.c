#include <stdio.h>
#include <string.h>

int main(void) {
    char *buf[100];

    printf("sizeof(buf) = %lu\n", sizeof(buf));
    printf("strlen(buf) = %lu\n", strlen(*buf));
    printf("%s\n", *buf);

    return 0;
}
