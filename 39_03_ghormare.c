#include <stdio.h>
#define SIZE 100

int arr[SIZE];
int top1 = -1, top2 = SIZE;

void push1(int value) {
    if (top1 < top2 - 1) arr[++top1] = value;
}

void push2(int value) {
    if (top1 < top2 - 1) arr[--top2] = value;
}

int pop1() {
    if (top1 >= 0) return arr[top1--];
    return -1;
}

int pop2() {
    if (top2 < SIZE) return arr[top2++];
    return -1;
}

int main() {
    push1(10);
    push2(20);
    push1(30);
    push2(40);
    printf("%d %d\n", pop1(), pop2());
    return 0;
}
