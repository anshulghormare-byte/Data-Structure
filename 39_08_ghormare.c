#include <stdio.h>
#include <string.h>
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

void reverse(char *expr) {
    int len = strlen(expr);
    for (int i = 0; i < len / 2; i++) {
        char temp = expr[i];
        expr[i] = expr[len - i - 1];
        expr[len - i - 1] = temp;
    }
    for (int i = 0; i < len; i++) {
        if (expr[i] == '(') expr[i] = ')';
        else if (expr[i] == ')') expr[i] = '(';
    }
}

void convert(char *expr) {
    reverse(expr);
    char result[SIZE];
    int k = 0;
    for (int i = 0; expr[i]; i++) {
        if (isalnum(expr[i])) {
            result[k++] = expr[i];
        } else if (expr[i] == '(') {
            push(expr[i]);
        } else if (expr[i] == ')') {
            while (peek() != '(') result[k++] = pop();
            pop();
        } else {
            while (top != -1 && precedence(peek()) >= precedence(expr[i])) {
                result[k++] = pop();
            }
            push(expr[i]);
        }
    }
    while (top != -1) result[k++] = pop();
    result[k] = '\0';
    reverse(result);
    printf("%s\n", result);
}

int main() {
    char expr[] = "a+b*c";
    convert(expr);
    return 0;
}
