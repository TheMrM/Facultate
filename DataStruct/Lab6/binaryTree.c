#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct Tree {
    TreeNode* root;
} Tree;

// Function prototypes
TreeNode* createTreeNode(int data);
Tree* createTree();
void insertTreeNode(TreeNode** node, int data);
void addTreeNode(Tree* tree, int data);
void inOrderTraversal(TreeNode* node);
void freeTreeNodes(TreeNode* node);
void freeTree(Tree* tree);

int main() {
    Tree* myTree = createTree();
    // Adding nodes to the tree
    addTreeNode(myTree, 10);
    addTreeNode(myTree, 5);
    addTreeNode(myTree, 15);
    addTreeNode(myTree, 3);
    addTreeNode(myTree, 7);
    addTreeNode(myTree, 12);
    
    printf("In-order Traversal of the BST:\n");
    inOrderTraversal(myTree->root);
    printf("\n");

    // Freeing the tree
    freeTree(myTree);

    return 0;
}

TreeNode* createTreeNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Tree* createTree() {
    Tree* newTree = (Tree*)malloc(sizeof(Tree));
    if (!newTree) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newTree->root = NULL;
    return newTree;
}

void insertTreeNode(TreeNode** node, int data) {
    if (*node == NULL) {
        *node = createTreeNode(data);
    } else if (data < (*node)->data) {
        insertTreeNode(&((*node)->left), data);
    } else if (data > (*node)->data) {
        insertTreeNode(&((*node)->right), data);
    }
}

void addTreeNode(Tree* tree, int data) {
    insertTreeNode(&(tree->root), data);
}

void inOrderTraversal(TreeNode* node) {
    if (node != NULL) {
        inOrderTraversal(node->left);
        printf("%d ", node->data);
        inOrderTraversal(node->right);
    }
}

void freeTreeNodes(TreeNode* node) {
    if (node != NULL) {
        freeTreeNodes(node->left);
        freeTreeNodes(node->right);
        free(node);
    }
}

void freeTree(Tree* tree) {
    freeTreeNodes(tree->root);
    free(tree);
}

