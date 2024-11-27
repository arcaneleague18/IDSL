#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;

// Function to insert a node into the binary search tree
void insert(int num) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->left = NULL;
    newnode->right = NULL;

    if (root == NULL) {
        root = newnode;
        return;
    }

    struct node* temp = root;
    while (temp != NULL) {
        if (newnode->data < temp->data) {
            if (temp->left == NULL) {
                temp->left = newnode;
                return;
            }
            temp = temp->left;
        } else {
            if (temp->right == NULL) {
                temp->right = newnode;
                return;
            }
            temp = temp->right;
        }
    }
}

// Function to perform a non-recursive preorder traversal
void preorderTraversal() {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    struct node* stack[100];
    int top = -1;
    stack[++top] = root;

    printf("Preorder Traversal: ");
    while (top >= 0) {
        struct node* current = stack[top--];
        printf("%d ", current->data);

        if (current->right != NULL) {
            stack[++top] = current->right;
        }
        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }
    printf("\n");
}

// Main function to handle user input
int main() {
    int choice, num;

        printf("\nMenu:\n");
        printf("1. Insert\n 2. Preorder Traversal\n 3. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number to insert: ");
                scanf("%d", &num);
                insert(num);
                break;

            case 2:
                preorderTraversal();
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
