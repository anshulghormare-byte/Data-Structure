#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void delete(int value) {
    struct Node *temp = head, *prev = NULL;
    while (temp && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp) {
        if (prev) prev->next = temp->next;
        else head = temp->next;
        free(temp);
    }
}

void reverse() {
    struct Node *prev = NULL, *curr = head, *next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void display() {
    struct Node *temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    display();
    delete(20);
    display();
    reverse();
    display();
    return 0;
}
