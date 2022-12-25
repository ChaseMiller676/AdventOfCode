#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

int top = -1;
char stack[SIZE];

void pop() {
    if (!(top >= 0)) {
	puts("Stack Underflow");
	exit(1);
    }

    top--;
}

void push(char val) {
    if (top == (SIZE - 1)) {
	puts("Stack Overflow");
	exit(1);
    }

    top++;
    stack[top] = val;
}

void show() {
    if (top < 0) {
	puts("Stack is Empty");
	return;
    }

    for (int i = 0; i < (top + 1); i++) {
	printf("%c", stack[i]);
    }

    putchar('\n');
}

int main(void)
{
    int input;
    char pushVal;

    while (1) {
	puts("1. Pop");
	puts("2. Push");
	puts("3. Show");
	puts("4. Quits");

	scanf("%i", &input);

	switch (input) {
	case 1:
	    pop();
	    break;
	case 2:
	    getchar();
	    puts("Enter a value to push");
	    scanf("%c", &pushVal);
	    push(pushVal);
	    break;
	case 3:
	    show();
	    break;
	case 4:
	    exit(0);
	}
    }
}
