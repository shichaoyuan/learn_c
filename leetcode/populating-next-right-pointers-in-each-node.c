#include<stdlib.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

void traverse(struct Node* a, struct Node* b) {
    if (a == NULL || b == NULL) {
        return;
    }

    a->next = b;
    traverse(a->left, a->right);
    traverse(b->left, b->right);
    traverse(a->right, b->left);
}

struct Node* connect(struct Node* root) {
    if (root) {
        traverse(root->left, root->right);
    }
	return root;
}
