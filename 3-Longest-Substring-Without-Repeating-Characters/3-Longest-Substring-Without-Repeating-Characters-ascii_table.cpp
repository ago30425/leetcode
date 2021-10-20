/*
 * Time: O(n)
 * Space: O(m), m is the size of the charset.
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(256, -1);
        int start = 0, ans = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (v[s[i]] >= start) {
                start =  v[s[i]] + 1;
            }
            
            v[s[i]] = i;
            ans = max(ans, i - start + 1);
        }
        
        return ans;
    }
};