#include <stdio.h>
#define SIZE 100

int arr[SIZE];
int f1 = -1, r1 = -1, f2 = SIZE, r2 = SIZE;

void enqueue1(int value) {
    if (r1 < SIZE / 2 - 1) {
        if (f1 == -1) f1 = 0;
        arr[++r1] = value;
    }
}

void enqueue2(int value) {
    if (r2 > SIZE / 2) {
        if (f2 == SIZE) f2 = SIZE - 1;
        arr[--r2] = value;
    }
}

int dequeue1() {
    if (f1 > r1 || f1 == -1) return -1;
    return arr[f1++];
}

int dequeue2() {
    if (f2 < r2 || f2 == SIZE) return -1;
    return arr[f2--];
}

int main() {
    enqueue1(10);
    enqueue2(20);
    enqueue1(30);
    enqueue2(40);
    printf("%d %d\n", dequeue1(), dequeue2());
    return 0;
}
