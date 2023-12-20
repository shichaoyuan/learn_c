#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildSubtree(int* preoder, int preStart, int preEnd, int* postorder, int postStart, int postEnd) {
    if (preStart > preEnd) {
        return NULL;
    }

    int rootVal = preoder[preStart];
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = rootVal;
    if (preStart == preEnd) {
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    int leftRootVal = preoder[preStart+1]; 
    int i = postStart;
    for (; i < postEnd; i++) {
        if (postorder[i] == leftRootVal) {
            break;
        }
    }
    node->left = buildSubtree(preoder, preStart+1, preStart+(i-postStart)+1, postorder, postStart, i);
    node->right = buildSubtree(preoder, preStart+(i-postStart)+1+1, preEnd, postorder, i+1, postEnd-1);
    return node;
}

struct TreeNode* constructFromPrePost(int* preorder, int preorderSize, int* postorder, int postorderSize) {
    return buildSubtree(preorder, 0, preorderSize-1, postorder, 0, postorderSize-1);
}