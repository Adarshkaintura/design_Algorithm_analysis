#include <bits/stdc++.h> 
int solution(vector<int> &nums,int n,vector<int> &dp){
    if(n<0){
       return 0;
    }
    if(n==0){
        return nums[0];
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int inc=solution(nums,n-2,dp)+nums[n];
    int exc=solution(nums,n-1,dp)+0;

    dp[n]=max(inc,exc);
    return dp[n];

}
//
int solutiontab(vector<int> &nums,int n){
   vector<int> dp(n,0);
       dp[0]=nums[0];
       for(int i=1;i<n;i++){
           int inc=dp[i-2]+nums[i];
           int exc=dp[i-1]+0;

           dp[i]=max(inc,exc);
       }
   return dp[n-1];
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n,-1);
    return solutiontab(nums,n);
}
