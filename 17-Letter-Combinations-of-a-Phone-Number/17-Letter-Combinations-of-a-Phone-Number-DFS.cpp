/* Time complexity: O(4^n)
 */
class Solution {
private:
    vector<string> phoneNums ={
        "",    "",    "abc",  "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"    
    };
    
    void dfs(string digits, int n, string &s, vector<string> &res) {
        if (n == digits.length()) {
            res.push_back(s);
            return;
        }
        
        for (const auto& c: phoneNums[digits[n] - '0']) {
            s.push_back(c);
            dfs(digits, n + 1, s, res);
            s.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string s;
        
        if (digits.empty())
            return {};
        
        dfs(digits, 0, s, res);
            
        return res;
    }
};