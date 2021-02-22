/*
 * Runtime: 8 ms, faster than 83.62% of C++ online submissions.
 * Memory Usage: 10.1 MB, less than 46.30% of C++ online submissions.
 */

#define SWAP(x, y) \
    if (x != y) {  \
         x ^= y;   \
         y ^= x;   \
         x ^= y;   \
    }

class Solution {
private:
    vector<int> heapArr;
    
    void heapify_up(int index) {
        int parent;
        
        if (index <= 0)
            return;
        
        parent = (index - 1) / 2;
        
        if (heapArr[parent] > heapArr[index]) {
            SWAP(heapArr[parent], heapArr[index]);
        }
        
        heapify_up(parent);
    }
    
    void heapify_down(int index) {
        int min = index;
        
        for (int i = 1; i <= 2; i++) {
            if (index * 2 + i < heapArr.size() &&
                heapArr[index * 2 + i] < heapArr[min])
                min = index * 2 + i;
        }
        
        if (min == index)
            return;
        
        SWAP(heapArr[min], heapArr[index]);
        
        heapify_down(min);
    }
    
    void heap_push(int num) {
        heapArr.push_back(num);
        
        heapify_up(heapArr.size() - 1);
    }
    
    void heap_pop(void) {
        if (heapArr.size() == 0)
            return;
        
        SWAP(heapArr[0], heapArr[heapArr.size() - 1]);
        heapArr.pop_back();
        
        heapify_down(0);
    }

public:
    /*
     * O(klogk) + O((n-k)(O(1) + log(k)))
     * = O(nlog(k))
     */
    int findKthLargest(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            /* O(klogk) */
            if (i < k) {
                heap_push(nums[i]);
                continue;
            }
            
            /* O((n-k)(O(1) + log(k))) */
            if (nums[i] > heapArr[0]) {
                heapArr.push_back(nums[i]);
                heap_pop();
            }
        }

        return heapArr[0];
    }
};




