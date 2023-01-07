/* Time: O(n log k)
 * Space: O(n)
 */

typedef pair<string, int> Node;

class Solution {
private:
    struct cmp {
        bool operator() (const Node &a, const Node &b) {
            if (a.second == b.second) {
                return (a.first < b.first);
            }

            return (a.second > b.second);
        }
    };

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        priority_queue<Node, vector<Node>, cmp> pq;
        vector<string> ans;

        /* O(n) */
        for (int i = 0; i < words.size(); i++) {
            count[words[i]]++;
        }

        /* O(n log k) */
        for (const auto &it: count) {
            pq.push(it);

            if (pq.size() > k) {
                pq.pop();
            }
        }

        /* O(k log (k)) */
        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }

        /* O(k) */
        reverse(ans.begin(), ans.end());

        return ans;
    }
};