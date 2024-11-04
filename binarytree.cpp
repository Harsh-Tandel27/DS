#include <stdio.h>
#include <stdlib.h>

// Node structure for BST
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
Node* insert(Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// Function to insert multiple nodes
void insertMultiple(Node** root) {
    int value;
    printf("Enter values to insert (separated by spaces, end with -1): ");
    while (scanf("%d", &value) && value != -1) {
        *root = insert(*root, value);
    }
}

// Traversal functions
void preorder(Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Function to delete a node from the BST
Node* deleteNode(Node* root, int data) {
    if (root == NULL) return root;
    
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = root->right;
        while (temp && temp->left)
            temp = temp->left;
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to convert the tree into its mirror image
void mirror(Node* root) {
    if (root) {
        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirror(root->left);
        mirror(root->right);
    }
}

// Functions to count nodes
int countNodes(Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countInternal(Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return 0;
    return 1 + countInternal(root->left) + countInternal(root->right);
}

int countExternal(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countExternal(root->left) + countExternal(root->right);
}

// Function to search a node
int search(Node* root, int data) {
    if (root == NULL) return 0;
    if (root->data == data) return 1;
    if (data < root->data) return search(root->left, data);
    return search(root->right, data);
}

// Function to find the height of the tree
int height(Node* root) {
    if (root == NULL) return -1;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Functions to find the minimum and maximum values in the BST
int findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root->data;
}

int findMax(Node* root) {
    while (root && root->right) root = root->right;
    return root->data;
}

// Main function
int main() {
    Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Insert Multiple\n2. Preorder Traversal\n3. Inorder Traversal\n4. Postorder Traversal\n5. Delete Node\n6. Mirror Image\n7. Count Nodes\n8. Search\n9. Height\n10. Find Smallest Element\n11. Find Largest Element\n12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertMultiple(&root);
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 6:
                printf("Inorder before mirroring: ");
                inorder(root);
                printf("\n");
                mirror(root);
                printf("Inorder after mirroring: ");
                inorder(root);
                printf("\nTree mirrored.\n");
                break;
            case 7:
                printf("Total Nodes: %d\n", countNodes(root));
                printf("Internal Nodes: %d\n", countInternal(root));
                printf("External Nodes: %d\n", countExternal(root));
                break;
            case 8:
                printf("Enter value to search: ");
                scanf("%d", &value);
                printf("Element %sfound.\n", search(root, value) ? "" : "not ");
                break;
            case 9:
                printf("Height of tree: %d\n", height(root));
                break;
            case 10:
                printf("Smallest element: %d\n", findMin(root));
                break;
            case 11:
                printf("Largest element: %d\n", findMax(root));
                break;
            case 12:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
