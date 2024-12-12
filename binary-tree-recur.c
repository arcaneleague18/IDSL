#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode() {
    int data;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL; 
    }

    struct Node* newNode = createNode(data);
    printf("Enter left child of %d:\n", data);
    newNode->left = insertNode();
    printf("Enter right child of %d:\n", data);
    newNode->right = insertNode();

    return newNode;
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int search(struct Node* root, int key) {
    if (root == NULL) {
        return 0; 
    }
    if (root->data == key) {
        return 1; 
    }
    return search(root->left, key) || search(root->right, key);
}

int main() {
    printf("Create the binary tree:\n");
    struct Node* root = insertNode();

    printf("\nIn-order Traversal: ");
    inOrder(root);
    printf("\n");

    printf("Pre-order Traversal: ");
    preOrder(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postOrder(root);
    printf("\n");

    int key;
    printf("\nEnter key to search in the binary tree: ");
    scanf("%d", &key);

    if (search(root, key)) {
        printf("Key %d is found in the binary tree.\n", key);
    } else {
        printf("Key %d is not found in the binary tree.\n", key);
    }

    return 0;
}
