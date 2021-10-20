/*
 * Time: O(n)
 * Space: O(m + n), The size of the Set is upper bounded by the size of the string n,
 * and the size of the charset/alphabet m.
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> umap;
        int start = 0, ans = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (umap.count(s[i])) {
                start = max(start, umap[s[i]] + 1);
            }
            
            umap[s[i]] = i;
            ans = max(ans, i - start + 1);
        }
        
        return ans;
    }
};
