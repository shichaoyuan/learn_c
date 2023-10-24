#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *head = NULL, **ptr = &head, **node;
    for (node = NULL; list1 && list2; *node = (*node)->next) {
        node = (list1->val < list2->val)? &list1: &list2;
        *ptr = *node;
        ptr = &(*ptr)->next;
    }
    *ptr = (struct ListNode *)((uintptr_t) list1 | (uintptr_t) list2);
    return head;
}

int main() {
    //输入：l1 = [1,2,4], l2 = [1,3,4]
    struct ListNode *node = NULL;
    node = malloc(sizeof(struct ListNode));
    node->next = NULL;
    node->val = 1;
    struct ListNode *list1 = node;
    node->next = malloc(sizeof(struct ListNode));
    node = node->next;
    node->next = NULL;
    node->val = 2;
    node->next = malloc(sizeof(struct ListNode));
    node = node->next;
    node->next = NULL;
    node->val = 4;


    node = malloc(sizeof(struct ListNode));
    node->next = NULL;
    node->val = 1;
    struct ListNode *list2 = node;
    node->next = malloc(sizeof(struct ListNode));
    node = node->next;
    node->next = NULL;
    node->val = 3;
    node->next = malloc(sizeof(struct ListNode));
    node = node->next;
    node->next = NULL;
    node->val = 4;

    struct ListNode *list = mergeTwoLists(list1, list2);

    for (node = list; node != NULL; node = node->next) {
        printf(" %d, ", node->val);
    }



}