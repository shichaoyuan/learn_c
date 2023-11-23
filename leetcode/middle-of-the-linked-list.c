#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *slow = head;
    for (struct ListNode *fast = head; fast && fast->next; fast = fast->next->next) {
        slow = slow->next;
    }
    return slow;
}