#include<stdlib.h>

void merge(int* nums, int l, int mid, int r, int* tmp) {
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
        } else if (tmp[i] > tmp[j]) {
            nums[p] = tmp[j++];
        } else {
            nums[p] = tmp[i++];
        }
    }

}

void sort(int* nums, int l, int r, int* tmp) {
    if (l == r) {
        return;
    }

    int mid = l + (r - l)/2;
    sort(nums, l, mid, tmp);
    sort(nums, mid+1, r, tmp);
    merge(nums, l, mid, r, tmp);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = nums;
    int* tmp = malloc(sizeof(int)*numsSize);
    sort(nums, 0, numsSize-1, tmp);
    free(tmp);
    return nums;
}