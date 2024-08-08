#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary tree
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node iteratively
void iterativeInsert(struct TreeNode** root, int value) {
    struct TreeNode* newNode = createNode(value);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    struct TreeNode* current = *root;
    struct TreeNode* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (value < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (value < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}

// Function to display the binary tree iteratively using inorder traversal
void iterativeDisplay(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct TreeNode* current = root;
    struct TreeNode* stack[100];
    int top = -1;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

// Function to find the node with given information and delete it
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL)
        return root;

    struct TreeNode* current = root;
    struct TreeNode* parent = NULL;

    while (current != NULL && current->data != key) {
        parent = current;
        if (key < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (current == NULL)
        return root; // Node with key not found

    // Case 1: Node with only one child or no child
    if (current->left == NULL) {
        struct TreeNode* temp = current->right;
        free(current);
        if (parent == NULL)
            return temp;
        if (key < parent->data)
            parent->left = temp;
        else
            parent->right = temp;
    } else if (current->right == NULL) {
        struct TreeNode* temp = current->left;
        free(current);
        if (parent == NULL)
            return temp;
        if (key < parent->data)
            parent->left = temp;
        else
            parent->right = temp;
    }

    // Case 2: Node with two children
    else {
        struct TreeNode* successor = current->right;
        while (successor->left != NULL)
            successor = successor->left;
        current->data = successor->data;
        current->right = deleteNode(current->right, successor->data);
    }

    return root;
}

// Function to free the memory of the binary tree
void freeTree(struct TreeNode* root) {
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct TreeNode* root = NULL;

    iterativeInsert(&root, 50);
    iterativeInsert(&root, 30);
    iterativeInsert(&root, 70);
    iterativeInsert(&root, 20);
    iterativeInsert(&root, 40);
    iterativeInsert(&root, 60);
    iterativeInsert(&root, 80);

    printf("Original Tree: ");
    iterativeDisplay(root);
    printf("\n");

    int keyToDelete = 30;
    root = deleteNode(root, keyToDelete);
    printf("Tree after deleting node with key %d: ", keyToDelete);
    iterativeDisplay(root);
    printf("\n");

    // Free the memory allocated for the tree
    freeTree(root);

    return 0;
}

