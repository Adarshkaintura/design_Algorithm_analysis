class Solution {
public:
int solve(int guess,int n,vector<vector<int>>& dp){
    if(guess>=n){
        return 0;
    }
    if(dp[guess][n]!=-1){
        return dp[guess][n];
    }
    int ans=INT_MAX;
    for(int i=guess;i<n;i++){
        ans=min(ans,i+max(solve(guess,i-1,dp),solve(i+1,n,dp)));
    }
    return dp[guess][n]=ans;
}
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(1,n,dp);

    }
};
