//brute reccursive tle
bool check(vector<int> arr, int n, int target) {
    if (n == 0) {
        return false;
    }
    if (target == 0) {
        return true;
    }
    if (arr[n - 1] <= target) {
        return check(arr, n - 1, target - arr[n - 1]) || check(arr, n - 1, target);
    } else {
        return check(arr, n - 1, target);
    }
}

bool isSubsetSum(vector<int> arr, int sum) {
    return check(arr, arr.size(), sum);
}
//dp optimized
bool check(vector<int> arr, int n, int sum, vector<vector<int>>& tab) {
    if (sum == 0)
        return true;
        
    if (n == 0)
        return false;
  
    if (tab[n - 1][sum] != -1)
        return tab[n - 1][sum];
  
    if (arr[n - 1] > sum)
        return tab[n - 1][sum] = check(arr, n - 1, sum, tab);
    else
        return tab[n - 1][sum] = check(arr, n - 1, sum, tab) || check(arr, n - 1, sum - arr[n - 1], tab);
}


bool isSubsetSum(vector<int> arr, int sum) {
    vector<vector<int>> dp(arr.size() + 1, vector<int>(sum+1, -1));
    return check(arr, arr.size(), sum, dp);
}
//i have a question why my the below code didn't word but the above one does even though both are same 
bool check(vector<int> arr, int n, int target, vector<vector<int>>& dp) {
    if (n == 0) {
        return false; 
    }
    if (target == 0) {
        return true;
    }
    if (dp[n-1][target] != -1) {
        return dp[n-1][target];
    }
    if (arr[n-1] <= target) {
        dp[n-1][target] = check(arr, n-1, target-arr[n-1], dp) || check(arr, n-1, target, dp);
        return dp[n-1][target];
    } else {
        dp[n-1][target] = check(arr, n-1, target, dp);
        return dp[n-1][target];
    }
}

bool isSubsetSum(vector<int> arr, int sum) {
    vector<vector<int>> dp(arr.size() + 1, vector<int>(sum+1, -1));
    return check(arr, arr.size(), sum, dp);
}

//tabular is easy do everything same but in forloop sum=j, n=i;
//checki in my notebook
bool isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    
    // Initialize the dp array
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true; // With 0 sum, we can always have an empty subset
    }
    
    for (int j = 1; j <= sum; j++) {
        dp[0][j] = false; // With no elements, we cannot achieve positive sums
    }
    
    // Fill the dp array
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    return dp[n][sum];
}
