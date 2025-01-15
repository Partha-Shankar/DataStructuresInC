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

// Inorder Traversal (Left -> Root -> Right)
void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

// Preorder Traversal (Root -> Left -> Right)
void preorder(node *root) {
    if (root != NULL) {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal (Left -> Right -> Root)
void postorder(node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

// Function to search for a key in the BST
node *search(node *root, int key) {
    while (root != NULL) {
        if (key == root->data) {
            return root;  // Key found
        } else if (key < root->data) {
            root = root->left;  // Search in the left subtree
        } else {
            root = root->right;  // Search in the right subtree
        }
    }
    return NULL;  // Key not found
}

// Function to find the node with the smallest value
node *minvalue(node *root) {
    while (root->left != NULL) {
        root = root->left;  // Move to the leftmost node
    }
    return root;
}

// Function to delete a node from the BST
node *deletekey(node *root, int key) {
    if (root == NULL) {
        return root;  // Tree is empty
    }

    if (key < root->data) {
        root->left = deletekey(root->left, key);  // Look in the left subtree
    } else if (key > root->data) {
        root->right = deletekey(root->right, key);  // Look in the right subtree
    } else {
        // Node with one or no child
        if (root->left == NULL) {
            node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor
        node *temp = minvalue(root->right);

        root->data = temp->data;  // Replace current node with successor's data
        root->right = deletekey(root->right, temp->data);  // Delete successor
    }

    return root;
}

// Main function
int main() {
    node *root = NULL;
    int ch, n, value, key;

    while (1) {
        printf("\nEnter\n1: Insert\t2: Traverse\t3: Search\t4: Delete\t5: Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter the number of elements: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("\nEnter value: ");
                    scanf("%d", &value);
                    root = insert(root, value);
                }
                break;

            case 2:
                if (root == NULL) {
                    printf("\nTree is empty\n");
                } else {
                    printf("\nInorder traversal:\n");
                    inorder(root);
                    printf("\nPreorder traversal:\n");
                    preorder(root);
                    printf("\nPostorder traversal:\n");
                    postorder(root);
                    printf("\n");
                }
                break;

            case 3:
                printf("\nEnter the key to search: ");
                scanf("%d", &key);
                if (search(root, key) != NULL) {
                    printf("\nKey found\n");
                } else {
                    printf("\nKey not found\n");
                }
                break;

            case 4:
                printf("\nEnter the key to delete: ");
                scanf("%d", &key);
                root = deletekey(root, key);
                break;

            case 5:
                exit(0);

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}
