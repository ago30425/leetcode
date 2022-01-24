/* Time complexity: O(log n)
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l, r, m;
        
        l = 0;
        r = nums.size();
        
        while (l < r) {
            m = (l + r) / 2;
            if (target <= nums[m]) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        
        return l;
    }
};
