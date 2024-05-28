//direct tabulation method i don't why my reccursive code is not working
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr = {1,2,3,3};
 
   
    vector<vector<int>> dp(arr.size() + 1, vector<int>(7));
    for(int i=0;i<5;i++){
        for(int j=0;j<7;j++){
             if(i==0){
                dp[i][j]=0;
             }
             if(j==0){
                dp[i][j]=1;
             }
        }
    }

   for(int i = 1; i <= 4; i++) {
    for(int j = 0; j <= 6; j++) {
        if (arr[i-1] <= j) {
            dp[i][j] = dp[i-1][j] + dp[i-1][j - arr[i-1]];
        } else {
            dp[i][j] = dp[i-1][j];
        }
    }
}

    cout << "The total count is: " << dp[arr.size()][6];
    return 0;
}

//optimized
#include <iostream>
#include <vector>

using namespace std;

int countSubsetsWithSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    
    // Initialize the dp array
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1; // There is one way to make a sum of 0: use the empty subset
    }
    
    // Fill the dp array
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            if (nums[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    return dp[n][target];
}

int main() {
    vector<int> nums = {2, 3, 5, 6, 8, 10};
    int target = 10;
    
    int result = countSubsetsWithSum(nums, target);
    cout << "Number of subsets with sum " << target << " is: " << result << endl;

    return 0;
}

