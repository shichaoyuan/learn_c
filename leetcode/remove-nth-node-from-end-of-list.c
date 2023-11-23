#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* fast = head;
    for (int i = 1; i < n; i++) {
        fast = fast->next;
        if (!fast) {
            return head;
        }
    }

    struct ListNode **indir = &head;
    while (fast->next) {
        indir = &(*indir)->next;
        fast = fast->next;
    }
    struct ListNode *del = *indir;
    *indir = (*indir)->next;
    free(del);
    return head;
}