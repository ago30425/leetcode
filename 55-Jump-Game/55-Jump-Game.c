/* Greedy algorithm */

bool canJump(int* nums, int numsSize){
    int i, max;
    
    if (nums == NULL || numsSize == 0)
        return true;
    
    max = 0;
    for (i = 0; i < numsSize && max < numsSize - 1; ++i){
        if (i + nums[i] > max)
            max = i + nums[i];
        
        /* Cannot forward. */
        if (max < i + 1)
            return false;
    }
    
    return true;
}