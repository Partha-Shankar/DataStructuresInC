#include <stdio.h>
#include <stdlib.h>

// Define the structure for the Binary Search Tree (BST)
struct BST {
    int data;
    struct BST *left, *right;
};
typedef struct BST node;

// Function to insert a node into the BST
node *insert(node *root, int value) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;

    if (root == NULL) {
        return newnode;  // If tree is empty, the new node becomes the root
    }

    node *current = root, *parent = NULL;
    while (current != NULL) {
        parent = current;
        if (value < current->data) {
            current = current->left;  // Move to the left subtree
        } else {
            current = current->right;  // Move to the right subtree
        }
    }

    if (value < parent->data) {
        parent->left = newnode;  // Attach as the left child
    } else {
        parent->right = newnode;  // Attach as the right child
    }

    return root;
}

// Main function
int main() {
    node *root = NULL;
    int value, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nBST Created Successfully.\n");
    return 0;
}
