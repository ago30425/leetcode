#define SWAP(x, y) \
    if (x != y) {  \
        x ^= y;    \
        y ^= x;    \
        x ^= y;    \
    }

void sortColors(int* nums, int numsSize){
    int i, j ,n;
    
    if (!nums || numsSize <= 1)
        return;
    
    i = n = 0;
    j = numsSize - 1;
    while (n <= j) {
        if (n > i && nums[n] == 0) {
            SWAP(nums[i], nums[n]);
            ++i;
        } else if (nums[n] == 2) {
            SWAP(nums[j], nums[n]);
            --j;
        } else {
            ++n;
        }
    }
}