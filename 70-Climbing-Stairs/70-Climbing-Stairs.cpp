class Solution {
public:
    int climbStairs(int n) {
        int prev1, prev2, res;
        
        if (n < 3)
            return n;
        
        prev1 = 1;
        prev2 = 2;
        for (int i = 2; i < n; i++) {
            res = prev1 + prev2;
            prev1 = prev2;
            prev2 = res;
        }
        
        return res;
    }
};