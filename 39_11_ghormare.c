#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int evaluate(char *expr) {
    for (int i = 0; expr[i]; i++) {
        if (isdigit(expr[i])) {
            push(expr[i] - '0');
        } else {
            int b = pop();
            int a = pop();
            switch (expr[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }
    return pop();
}

int main() {
    char expr[] = "23*54*+9-";
    printf("%d\n", evaluate(expr));
    return 0;
}
