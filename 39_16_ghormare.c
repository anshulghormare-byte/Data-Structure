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

int findMin(struct Node* root) {
    if (!root) return -1;
    while (root->left) root = root->left;
    return root->data;
}

int findMax(struct Node* root) {
    if (!root) return -1;
    while (root->right) root = root->right;
    return root->data;
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

    printf("Minimum: %d\n", findMin(root));
    printf("Maximum: %d\n", findMax(root));
    return 0;
}
