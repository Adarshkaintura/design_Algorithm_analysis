class Solution {
public:

 int helper(string ring,string key,int ptr,int index,vector<vector<int>>& dp){
    int n=ring.size();
    int m=key.size();
    if(index>=m){
        return 0;
    }
    if(dp[ptr][index]!=-1){
        return dp[ptr][index];
    }
    int step=1e8;
    for(int i=0;i<n;i++){
        if(ring[i]==key[index]){
            step=min(step,min(abs(i-ptr),n-abs(i-ptr))+1+helper(ring,key,i,index+1,dp));
            dp[ptr][index]=step;
        }
    }
    return dp[ptr][index];
 }
    int findRotateSteps(string ring, string key) {
        int n=ring.size();
        int m=key.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
       return helper(ring,key,0,0,dp); 
    }
};
