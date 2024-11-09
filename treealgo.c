#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int getSize(struct Node* root) {
    if (!root) return 0;
    return 1 + getSize(root->left) + getSize(root->right);
}

int getHeight(struct Node* root) {

    if (!root) return -1;
    int leftH = getHeight(root->left);
    int rightH = getHeight(root->right);
    return 1 + (leftH > rightH ? leftH : rightH);
}

int findLevel(struct Node* root, int val, int level) {
    if (!root) return -1;
    
    if (root->data == val) return level;
    int leftL = findLevel(root->left, val, level + 1);
    if (leftL != -1) return leftL;
    return findLevel(root->right, val, level + 1);
}

int main() {
    struct Node* root = newNode(1);


    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Tree size: %d\n", getSize(root));
    printf("Tree height: %d\n", getHeight(root));
    int target = 5;
    int lvl = findLevel(root, target, 0);
    if (lvl != -1){
        printf("Node %d is at level: %d\n", target, lvl);
    }
    else {
        printf("Node %d not found\n", target);
    }

    
}
