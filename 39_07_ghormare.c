#include <stdio.h>
#include <ctype.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    return 0;
}

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

void convert(char *expr) {
    for (int i = 0; expr[i]; i++) {
        if (isalnum(expr[i])) {
            printf("%c", expr[i]);
        } else if (expr[i] == '(') {
            push(expr[i]);
        } else if (expr[i] == ')') {
            while (peek() != '(') printf("%c", pop());
            pop();
        } else {
            while (top != -1 && precedence(peek()) >= precedence(expr[i])) {
                printf("%c", pop());
            }
            push(expr[i]);
        }
    }
    while (top != -1) printf("%c", pop());
    printf("\n");
}

int main() {
    char expr[] = "a+b*c";
    convert(expr);
    return 0;
}
