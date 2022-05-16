/* Time complexity:  O(log n)
 * Space complexity: O(1)
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int m, l, r;
        
        l = 0;
        r = nums.size() - 1;
        m = (l + r) / 2;
        while(l <= r) {
            m = (l + r) / 2;
             
            if (target == nums[m])
                return m;
            
            if (nums[m] > nums[r]) {
                if (target >= nums[l] && target < nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            } else {
                if (target > nums[m] && target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        
        return -1;
    }
};