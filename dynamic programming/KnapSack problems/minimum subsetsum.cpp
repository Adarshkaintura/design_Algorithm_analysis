//minimum subset sum difference 
/*  The Minimum Subset Sum Difference problem involves partitioning a given set into two subsets such that the difference between the sums of the subsets is minimized.
Problem Statement

Given a set of positive integers, we need to divide the set into two subsets such that the difference between the sum of elements in both subsets is minimized.
Example

Let's consider a set of positive integers: {1, 6, 11, 5}.

We want to partition this set into two subsets such that the difference between the sums of elements in the two subsets is minimized.

Test Case:

    Input: Set = {1, 6, 11, 5}
    Output: Minimum Subset Sum Difference = 1
    Explanation: One possible partition is {1, 6, 5} and {11}. The sum of the first subset is 12 and the sum of the second subset is 11, resulting in a difference of 1.*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int minSubsetSumDifference(vector<int>& nums) {
    int n = nums.size();
    int totalSum = 0;
    
    // Calculate total sum of the set
    for (int num : nums) {
        totalSum += num;
    }
    
    // Create a DP table to store possible sums of subsets
    vector<vector<bool>> dp(n + 1, vector<bool>(totalSum + 1, false));
    
    // Initialize the DP table
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true; // A sum of 0 can always be achieved with an empty subset
    }
    
    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= totalSum; j++) {
            if (nums[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    // Find the minimum subset sum difference
    int minDiff = INT_MAX;
    for (int j = totalSum / 2; j >= 0; j--) {
        if (dp[n][j]) {
            minDiff = min(minDiff, totalSum - 2 * j);
            break;
        }
    }
    
    return minDiff;
}

int main() {
    vector<int> nums = {1, 6, 11, 5};
    
    int minDiff = minSubsetSumDifference(nums);
    cout << "Minimum Subset Sum Difference: " << minDiff << endl;

    return 0;
}
