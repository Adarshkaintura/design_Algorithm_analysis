class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();

        if (k == 0) {
            return (n >= 1) ? nums[0] : -1;
        }

        if (n == 1) {
            // Special case: only one element
            // After odd number of ops, stack will be empty
            // You can push back only once
            return (k % 2 == 0) ? nums[0] : -1;
        }

        if (k == 1) {
            return nums.size() >= 2 ? nums[1] : -1;
        }

        if (k > n) {
            return *max_element(nums.begin(), nums.end());
        }

        int maxVal = INT_MIN;
        for (int i = 0; i < k - 1 && i < nums.size(); i++) {
            maxVal = max(maxVal, nums[i]);
        }

        if (k < nums.size()) {
            maxVal = max(maxVal, nums[k]);
        }

        return maxVal;
    }
};
