

int findPeakElement(int* nums, int numsSize){
    int left, mid, right;

    if (!nums || numsSize == 0)
        return -1;
    
    left = 0;
    right = numsSize - 1;
    while (right > left) {
        mid = (left + right) / 2;

        if (nums[mid] > nums[mid + 1])
            right = mid;
        else
            left = mid + 1;
    }
    
    return left;
}