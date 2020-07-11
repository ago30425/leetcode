

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

typedef struct threeSum{
    int *triplet;
    struct threeSum *next;
} threeSum_t;

threeSum_t *
LinkedList_Append(threeSum_t **head, threeSum_t *tail) {
    threeSum_t* node = (threeSum_t *)malloc(sizeof(threeSum_t));
    if (!node)
        return NULL;

    if (!*head)
        *head = tail = node;
    else {
        tail->next = node;
        tail = node;
    }
    node->next = NULL;
    
    return node;
}

void LinkedList_Delete(threeSum_t **head) {
    threeSum_t *tmp;
    
    while (*head) {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}

void LinkedList2Array(threeSum_t *head, int **array, int **sizes) {
    int i = 0;
    threeSum_t *cur;

    cur = head;
    while (cur) {
        array[i] = cur->triplet;
        if (*sizes)
            (*sizes)[i] = 3;
        cur = cur->next;
        ++i;
    }
}

inline void swap (int *x, int *y) {
    if (*x == *y)
        return;
    
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}

static int partition(int* nums, int left, int right) {
    int i, j;
    int pivot;

    if (left >= right)
        return -1;
    
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

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i, start, end;
    int target;
    int size;
    threeSum_t *threeSumHead, *threeSumTail;
    int **res, *triplet;

    if (!nums || !returnSize || !returnColumnSizes)
        return NULL;

    q_sort(nums, 0, numsSize - 1);

    size = 0;
    threeSumHead = threeSumTail = NULL;
    for (i = 0; i <= numsSize - 3; ++i) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        start = i + 1;
        end = numsSize - 1;
        target = -nums[i];
        while (end > start) {
            if (nums[start] + nums[end] > target) {
                --end;
            }
            else if (nums[start] + nums[end] < target) {
                ++start;
            } else {
                if (size == 0 ||
                    (threeSumTail->triplet[0] != nums[i]) ||
                    (threeSumTail->triplet[1] != nums[start])) {
                    threeSumTail = LinkedList_Append(&threeSumHead, threeSumTail);
                    if (!threeSumTail)
                        break;
                    
                    triplet = (int *)malloc(sizeof(int) * 3);
                    if (!triplet)
                     break;
                
                    triplet[0] = nums[i];
                    triplet[1] = nums[start];
                    triplet[2] = nums[end];
                
                    threeSumTail->triplet = triplet;
                    ++size;
                }
                ++start;
            }
        }
    }

    res = (int **) malloc(sizeof(int *) * size);
    if (!res)
        return NULL;
        
    *returnColumnSizes = (int *)malloc(sizeof(int) * size);
    
    LinkedList2Array(threeSumHead, res, returnColumnSizes);
    LinkedList_Delete(&threeSumHead);
    
    *returnSize = size;

    return res;
}