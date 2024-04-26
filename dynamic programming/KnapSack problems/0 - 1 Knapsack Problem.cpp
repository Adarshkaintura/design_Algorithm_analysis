//brute force 
 int knapSack(int W, int wt[], int val[], int n) 
    { 
      if(n==0 || W==0){
          return 0;
      }
      if(W>=wt[n-1]){
          return max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
      }
      else if(W<wt[n-1]){
          return knapSack(W,wt,val,n-1);
      }
    }
//optimized
 int helper(int W, int wt[], int val[], int n, vector<vector<int>>& dp) {
    if(n == 0 || W == 0) {
        return 0;
    }
    if(dp[n][W] != -1) {
        return dp[n][W];
    }
    if(W >= wt[n - 1]) {
        dp[n][W] = max(val[n - 1] + helper(W - wt[n - 1], wt, val, n - 1, dp), helper(W, wt, val, n - 1, dp));
        return dp[n][W];
    }
    else {
        dp[n][W] = helper(W, wt, val, n - 1, dp);
        return dp[n][W];
    }
}

int knapSack(int W, int wt[], int val[], int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1)); // Corrected initialization
    return helper(W, wt, val, n, dp);
}
