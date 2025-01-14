#include <stdio.h>
#include <stdlib.h>

struct BST {
    int data;
    struct BST *left, *right;
};
typedef struct BST node;

node *insert(node *root, int value) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;

    if (root == NULL) {
        return newnode;
    }

    node *current = root, *parent = NULL;
    while (current != NULL) {
        parent = current;
        if (value < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (value < parent->data) {
        parent->left = newnode;
    } else {
        parent->right = newnode;
    }

    return root;
}

void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

void preorder(node *root) {
    if (root != NULL) {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

// Search for a key in the BST
node *search(node *root, int key) {
    while (root != NULL) {
        if (key == root->data) {
            return root;
        } else if (key < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return NULL;
}

int main() {
    node *root = NULL;
    int value, n, key;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nInorder traversal:\n");
    inorder(root);
    printf("\nPreorder traversal:\n");
    preorder(root);
    printf("\nPostorder traversal:\n");
    postorder(root);

    printf("\nEnter the key to search: ");
    scanf("%d", &key);
    if (search(root, key) != NULL) {
        printf("\nKey found.\n");
    } else {
        printf("\nKey not found.\n");
    }

    return 0;
}
