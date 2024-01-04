#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void traverse(struct TreeNode *node, int* sum) {
    if (!node)
        return;
    traverse(node->right, sum);
    *sum += node->val;
    node->val = *sum;
    traverse(node->left, sum);
}

struct TreeNode* convertBST(struct TreeNode* root) {
    int sum = 0;
    traverse(root, &sum);
    return root;
}
