class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end()); // Initialize r to the maximum pile size
        
        int ans = r;
        while (l <= r) {
            int m = l + (r - l) / 2; // To avoid potential overflow
            
            long long hr = 0;
            for (int pile : piles) {
                hr += (pile + m - 1) / m; // Calculate hours needed to eat each pile at speed m
            }
            
            if (hr <= h) {
                ans = m;
                r = m - 1; // Try for a smaller eating speed
            } else {
                l = m + 1; // Increase the eating speed
            }
        }
        return ans;
    }
};
