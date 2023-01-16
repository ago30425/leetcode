class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /* O(n) */
        priority_queue<int> pq(nums.begin(), nums.end());

        /* O(k) */
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }

        return pq.top();
    }
};