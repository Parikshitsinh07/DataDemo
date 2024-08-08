#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
    int is_threaded;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    newNode->is_threaded = 0; // Initialize as not threaded
    return newNode;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key) {
        root->left = insert(root->left, key);
        if (root->left->right == NULL) {
            root->left->right = root;
            root->left->is_threaded = 1;
        }
    }
    else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

struct Node* leftmost(struct Node* node) {
    while (node != NULL && node->left != NULL)
        node = node->left;
    return node;
}

void display(struct Node* root) {
    struct Node* current = leftmost(root);

    while (current != NULL) {
        printf("%d ", current->key);

        if (current->right != NULL && !current->is_threaded)
            current = leftmost(current->right);
        else
            current = current->right;
    }
}

int main() {
    struct Node* root = NULL;
    int keys[] = {8, 3, 10, 1, 6, 9, 14, 4, 7, 13};
    int num_keys = sizeof(keys) / sizeof(keys[0]);
	int i;
    for ( i = 0; i < num_keys; ++i)
        root = insert(root, keys[i]);

    display(root);

    return 0;
}

