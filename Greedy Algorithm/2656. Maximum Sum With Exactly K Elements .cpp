class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxVal = *max_element(nums.begin(), nums.end());
        return k * maxVal + (k * (k - 1)) / 2;
    }
};
