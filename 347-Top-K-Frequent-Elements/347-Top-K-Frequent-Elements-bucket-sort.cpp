/*
 * Time: O(n)
 * Space: O(n)
 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        unordered_map<int, vector<int>> buckets;
        vector<int> ans;
        int max_freq = 1;
        
        /* O(n) */
        for (int i = 0; i < nums.size(); i++) {
            max_freq = max(max_freq, ++freq[nums[i]]);
        }

        /* O(n) */
        for (const auto &it: freq) {
            buckets[it.second].push_back(it.first);
        }

        /* O(n) */
        for (int i = max_freq; i >= 1; i--) {
            auto it = buckets.find(i);

            if (it == buckets.end()) {
                continue;
            }

            ans.insert(ans.end(), it->second.begin(), it->second.end());
            if (ans.size() == k) {
                break;
            }
        }

        return ans;
    }
};