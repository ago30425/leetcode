/*
 * Runtime: 12 ms, faster than 97.45%.
 * Memory Usage: 13.8 MB, less than 78.09%.
 */
class Solution {
private:
    void swap(vector<pair<int, int>> &maxHeap, int x, int y) {
        pair<int, int> tmp;
        
        tmp = maxHeap[x];
        maxHeap[x] = maxHeap[y];
        maxHeap[y] = tmp;
    }
    
    void heapify_down(vector<pair<int, int>> &maxHeap, int parent) {
        int max = parent;
        
        for (int i = 2 * (parent + 1); i > parent * 2; --i) {
            if (i < maxHeap.size() &&
                maxHeap[i].second > maxHeap[max].second)
                max = i;
        }
        
        if (max == parent)
            return;
        
        swap(maxHeap, max, parent);
        
        heapify_down(maxHeap, max);
    }

    void maxheap_create(vector<pair<int, int>> &maxHeap) {
        for (int i = maxHeap.size() - 1; i >= 0; --i) {
            heapify_down(maxHeap, i);
        }
    }

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;    // space: O(n)
        vector<pair<int, int>> maxHeap; // space: O(n)
        vector<int> ans;
        
        /* time: O(n) */
        for (const auto &it : nums) {
            ++map[it];
        }
        
        /* time: O(n) */
        for (const auto &it : map) {
            maxHeap.push_back(make_pair(it.first, it.second));
        }
        
        /* time: O(n) */
        maxheap_create(maxHeap);
        
        /* time: O(klogk) */
        for (int i = 0; i < k; ++i) {
            swap(maxHeap, 0, maxHeap.size() - 1); 
            ans.push_back(maxHeap.back().first);
            maxHeap.pop_back();
            heapify_down(maxHeap, 0);
        }
        
        return ans;
    }
};