class Solution {
public:
    int solve(vector<int>& nums,int i,int j,vector<vector<int>>& dp){
      if(i>j){
        return 0;
      }
      if(dp[i][j]!=-1){
        return dp[i][j];
      }
     int take_i=nums[i]+min(solve(nums,i+2,j,dp),solve(nums,i+1,j-1,dp));
     int take_j=nums[j]+min(solve(nums,i+1,j-1,dp),solve(nums,i,j-2,dp));
      return dp[i][j]=max(take_i,take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int sum=0;
       for(int i=0;i<nums.size();i++){
        sum += nums[i];
       }
       int score=solve(nums,0,nums.size()-1,dp); 
       int a=sum-score;
       if(score>=a){
        return true;
       }
       return false;
    }
};
