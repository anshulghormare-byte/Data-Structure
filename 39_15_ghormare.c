#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (!root) return createNode(value);
    if (value < root->data) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);
    return root;
}

void printRange(struct Node* root, int low, int high) {
    if (!root) return;
    if (low < root->data) printRange(root->left, low, high);
    if (low <= root->data && root->data <= high) printf("%d ", root->data);
    if (high > root->data) printRange(root->right, low, high);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    int low = 35, high = 75;
    printRange(root, low, high);
    return 0;
}
