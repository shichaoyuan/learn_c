#include<stdlib.h>

struct pair {
    int val;
    int id;
};

void merge(struct pair *nums, int l, int mid, int r, struct pair *tmp, int* count) {
    for (int i = l; i <= r; i++) {
        tmp[i] = nums[i];
    }

    int i = l;
    int j = mid + 1;
    for (int p = l; p <= r; p++) {
        if (i == mid + 1) {
            nums[p] = tmp[j++];
        } else if (j == r + 1) {
            nums[p] = tmp[i++];
            count[nums[p].id] += j - mid - 1;
        } else if (tmp[i].val > tmp[j].val) {
            nums[p] = tmp[j++];
        } else {
            nums[p] = tmp[i++];
            count[nums[p].id] += j - mid - 1;
        }
    }

}

void sort(struct pair *nums, int l, int r, struct pair *tmp, int* count) {
    if (l == r) {
        return;
    }

    int mid = l + (r - l)/2;
    sort(nums, l, mid, tmp, count);
    sort(nums, mid+1, r, tmp, count);
    merge(nums, l, mid, r, tmp, count);
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* count = malloc(sizeof(int)*numsSize);
    memset(count, 0, sizeof(int)*numsSize);
    struct pair *arr = malloc(sizeof(struct pair)*numsSize);
    struct pair *tmp = malloc(sizeof(struct pair)*numsSize);
    for (int i = 0; i < numsSize; i++) {
        struct pair p = { nums[i], i };
        arr[i] = p;
    }
    sort(arr, 0, numsSize-1, tmp, count);
    free(arr);
    free(tmp);
    return count;
}