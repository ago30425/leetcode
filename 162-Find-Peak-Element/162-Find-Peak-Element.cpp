/* Time complexity:  O(log n)
 * Space complexity: O(1)
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int m, l, r;
        
        l = 0;
        r = nums.size() - 1;
        m = (l + r) / 2;
        while (r > l) {
            if (nums[m] < nums[m + 1])
                l = m + 1;
            else
                r = m;

            m = (l + r) / 2;
        }
        
        return m;
    }
};