#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildSubtree(int* preoder, int preStart, int preEnd, int* inorder, int inStart, int inEnd) {
    if (preStart > preEnd) {
        return NULL;
    }

    int rootVal = preoder[preStart];
    int i = inStart;
    for (; i <= inEnd; i++) {
        if (inorder[i] == rootVal) {
            break;
        }
    }
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = rootVal;
    node->left = buildSubtree(preoder, preStart+1, preStart+(i-inStart), inorder, inStart, i-1);
    node->right = buildSubtree(preoder, preStart+(i-inStart)+1, preEnd, inorder, i+1, inEnd);
    return node;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    return buildSubtree(preorder, 0, preorderSize-1, inorder, 0, inorderSize-1);
}
