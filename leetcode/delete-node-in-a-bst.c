struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* getMin(struct TreeNode *node) {
    while (node->left) {
        node = node->left;
    }
    return node;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (!root)
        return root;
    if (root->val == key) {
        if (!root->left) {
            return root->right;
        } else if (!root->right) {
            return root->left;
        } else {
            struct TreeNode *min = getMin(root->right);
            root->right = deleteNode(root->right, min->val);
            min->left = root->left;
            min->right = root->right;
            root = min;
        }
    } else if (root->val > key) {
        root->left = deleteNode(root->left, key);
    } else {
        root->right = deleteNode(root->right, key);
    }
    return root;
}