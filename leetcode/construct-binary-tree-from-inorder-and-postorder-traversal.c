#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildSubtree(int* inorder, int inStart, int inEnd, int* postorder, int postStart, int postEnd) {
    if (inStart > inEnd) {
        return NULL;
    }

    int rootVal = postorder[postEnd];
    int i = inStart;
    for (; i <= inEnd; i++) {
        if (inorder[i] == rootVal) {
            break;
        }
    }
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = rootVal;
    node->left = buildSubtree(inorder, inStart, i-1, postorder, postStart, postStart+(i-inStart)-1);
    node->right = buildSubtree(inorder, i+1, inEnd, postorder, postStart+(i-inStart), postEnd-1);
    return node;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    return buildSubtree(inorder, 0, inorderSize-1, postorder, 0, postorderSize-1);   
}