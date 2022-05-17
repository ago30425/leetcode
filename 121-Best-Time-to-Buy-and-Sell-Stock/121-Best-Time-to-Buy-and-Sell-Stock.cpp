/* Time complexity: O(n)
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = prices[0];
        
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1])
                maxProfit = max(maxProfit, prices[i] - minPrice);
            else
                minPrice = min(minPrice, prices[i]);
        }
            
        return maxProfit;
    }
};