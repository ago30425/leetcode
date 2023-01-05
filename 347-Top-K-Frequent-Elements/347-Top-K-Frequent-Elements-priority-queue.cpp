/*
 * Time: O(n) + O(nlogk)
 * Space: O(n)
 */

typedef pair<int, int> pii;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> ans;

        /* O(n) */
        for (int i = 0; i < nums.size(); i++) {
            um[nums[i]]++;
        }

        /* O(n log k) */
        for (const auto &it: um) {
            pq.push({it.second, it.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        /* O(k log k) */
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};