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

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (!listsSize) {
        return NULL;
    }
    if (listsSize == 1) {
        return *lists;
    }

    int m = listsSize >> 1;
    struct ListNode* left = mergeKLists(lists, m);
    struct ListNode* right = mergeKLists(lists + m, listsSize - m);
    return mergeTwoLists(left, right);
}


int main() {
    // lists = [[1,4,5],[1,3,4],[2,6]]
    struct ListNode *node = NULL;
    node = malloc(sizeof(struct ListNode));
    node->next = NULL;
    node->val = 1;
    struct ListNode *list1 = node;
    node->next = malloc(sizeof(struct ListNode));
    node = node->next;
    node->next = NULL;
    node->val = 4;
    node->next = malloc(sizeof(struct ListNode));
    node = node->next;
    node->next = NULL;
    node->val = 5;


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

    node = malloc(sizeof(struct ListNode));
    node->next = NULL;
    node->val = 2;
    struct ListNode *list3 = node;
    node->next = malloc(sizeof(struct ListNode));
    node = node->next;
    node->next = NULL;
    node->val = 6;

    struct ListNode *lists[3] = {list1, list2, list3};

    struct ListNode *list = mergeKLists(lists, 3);

    for (node = list; node != NULL; node = node->next) {
        printf(" %d, ", node->val);
    }



}



 