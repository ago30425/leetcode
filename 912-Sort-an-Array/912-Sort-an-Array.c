

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void swap(int *x, int *y) {
    if (*x != *y) { // avoid the address of x and y are the same.
        *x ^= *y;
        *y ^= *x;
        *x ^= *y;
    }
}

int partition(int* nums, int left, int right) {
    int i, j;
    int pivot;

    if (left >= right)
        return;
    
    pivot = nums[right];
    j = left - 1;
    for (i = left; i < right; ++i) {
        if (nums[i] < pivot) {
            ++j;
            swap(&nums[i], &nums[j]);
        }
    }
    
    swap(&nums[++j], &nums[right]);
    
    return j;
}

void q_sort(int* nums, int left, int right) {
    int pivot;
    
    if (left >= right)
        return;
    
    pivot = partition(nums, left, right);
    
    q_sort(nums, left, pivot - 1);
    q_sort(nums, pivot + 1, right);
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    q_sort(nums, 0, numsSize - 1);
    
    *returnSize = numsSize;

    return nums;
}