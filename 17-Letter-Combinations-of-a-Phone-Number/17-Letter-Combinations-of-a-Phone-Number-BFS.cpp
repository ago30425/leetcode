/* Time complexity: O(4^n)
 */
class Solution {
private:
    vector<string> phoneNum ={
        "",    "",    "abc",  "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"    
    };
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        
        if (digits.empty())
            return {};
        
        res.push_back("");
        for (const auto &d: digits) {
            vector<string> tmp;
            for (const auto &c: phoneNum[d - '0']) {
                for (const auto &r: res) {
                    tmp.push_back(r + c);
                }
            }
            res.swap(tmp);
        }
        
        return res;
    }
};