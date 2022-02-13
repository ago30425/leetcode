/*
 * Time: O(n)
 * Space: O(n)
 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<pair<int, int>> stack;
        size_t size = temperatures.size();
        vector<int> res(size);
        
        for (int i = 0; i < size; i++) {
            while (!stack.empty()) {
                pair<int, int> temp = stack.back();

                if (temperatures[i] > temp.first) {
                    res[temp.second] = i - temp.second;
                    stack.pop_back();

                    continue;
                }

                break;
            }
                
            stack.push_back(make_pair(temperatures[i], i));
        }
        
        /* Cannot find out the warmer temperature */
        while (!stack.empty()) {
            res[stack.back().second] = 0;
            stack.pop_back();
        }
        
        return res;
    }
};