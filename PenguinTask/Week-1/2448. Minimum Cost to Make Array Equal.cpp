//brute 
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ans = LLONG_MAX;
        for(int i = 0; i < nums.size(); i++) {
            long long temp = 0;
            for(int j = 0; j < nums.size(); j++) {
                long long a = abs(nums[i] - nums[j]);
                a *= cost[j];
                temp += a;
            }
            ans = min(ans, temp);
        }
        return ans;
    }
};

