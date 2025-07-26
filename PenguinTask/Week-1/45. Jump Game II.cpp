//brute reccursive code tle is their
class Solution {
public:
    int ans = INT_MAX;

    void solve(vector<int>& nums, int idx, int n, int steps) {
        if (steps >= ans) return; 

        if (idx >= n - 1) {
            ans = min(ans, steps);
            return;
        }

        for (int i = 1; i <= nums[idx]; i++) {
            solve(nums, idx + i, n, steps + 1);
        }
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        solve(nums, 0, n, 0);
        return ans;
    }
};
//optimized still tle
class Solution {
public:
    int ans = INT_MAX;
    vector<int> dp;

    void solve(vector<int>& nums, int idx, int steps) {
        if (steps >= ans) return; 

        if (idx >= nums.size() - 1) {
            ans = min(ans, steps);
            return;
        }

        if (dp[idx] != -1 && dp[idx] <= steps) return;
        dp[idx] = steps;

        for (int i = 1; i <= nums[idx]; i++) {
            solve(nums, idx + i, steps + 1);
        }
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, -1);
        solve(nums, 0, 0);
        return ans;
    }
};
class Solution {
public:
    int jump(vector<int>& nums) {
       int n=nums.size();
       int steps=0;
       int jumps=0;
      int cend=0;
       for(int i=0;i<n-1;i++){
      steps=max(steps,i+nums[i]);
      if(cend==i){
        cend=steps;
        jumps++;
      }
       }
        return jumps;
    }
};

