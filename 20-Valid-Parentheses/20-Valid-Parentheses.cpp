class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        map<char, char> map;
        bool ret = false;
        
        map[']'] = '[';
        map[')'] = '(';
        map['}'] = '{';
        
        for (const auto &c: s) {
            if (c == '[' || c == '(' || c == '{') {
                stack.push_back(c);
            } else if (stack.empty() || map[c] != stack.back()) {
                return false;
            } else {
                stack.pop_back();
            }
        }
        
        if (stack.empty()) {
            ret = true;
        }

        return ret;
    }
};
