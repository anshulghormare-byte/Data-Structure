#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 26

struct Trie {
    struct Trie *children[SIZE];
    int isEnd;
};

struct Trie *createNode() {
    struct Trie *node = malloc(sizeof(struct Trie));
    node->isEnd = 0;
    for (int i = 0; i < SIZE; i++) node->children[i] = NULL;
    return node;
}

void insert(struct Trie *root, char *word) {
    struct Trie *curr = root;
    for (int i = 0; word[i]; i++) {
        int index = word[i] - 'a';
        if (!curr->children[index]) curr->children[index] = createNode();
        curr = curr->children[index];
    }
    curr->isEnd = 1;
}

int search(struct Trie *root, char *word) {
    struct Trie *curr = root;
    for (int i = 0; word[i]; i++) {
        int index = word[i] - 'a';
        if (!curr->children[index]) return 0;
        curr = curr->children[index];
    }
    return curr->isEnd;
}

int main() {
    struct Trie *root = createNode();
    insert(root, "hello");
    insert(root, "world");
    printf("%s\n", search(root, "hello") ? "Found" : "Not Found");
    printf("%s\n", search(root, "word") ? "Found" : "Not Found");
    return 0;
}
