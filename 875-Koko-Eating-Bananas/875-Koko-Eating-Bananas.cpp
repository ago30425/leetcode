/* Time complexity: O(hlogn)
 */
class Solution {
private:
    int _find_max(vector<int>& piles) {
        int max = 0;
        
        for (const auto &p: piles) {
            if (p > max)
                max = p;
        }
        
        return max;
    }
    
    int _calculate_hours(int k, vector<int>& piles) {
        int hour = 0, n;
        
        for (const auto &p: piles) {
            hour += (p + k - 1) / k;
        }
        
        return hour;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = _find_max(piles), m;
        
        while (r > l) {
            m = (l + r) / 2;
            
            if (_calculate_hours(m, piles) > h)
                l = m + 1;
            else
                r = m;
        }
        
        return l;
    }
};