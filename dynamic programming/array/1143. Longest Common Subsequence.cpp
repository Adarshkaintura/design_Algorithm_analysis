//reccusive approach
class Solution {
public:
int solve(string s1,string s2,int i,int j){
    if(i>=s1.length()||j>=s2.length()){
           return 0;
    }
    if(s1[i]==s2[j]){
        return 1+solve(s1,s2,i+1,j+1);
    }else{
        return max(solve(s1,s2,i+1,j),solve(s1,s2,i,j+1));
    }
}
    int longestCommonSubsequence(string text1, string text2) {
     
     return solve(text1,text2,0,0);
    }
};
//memorization
class Solution {
public:
int solve(string s1,string s2,int i,int j,vector<vector<int>>& dp){
    if(i>=s1.length()||j>=s2.length()){
           return 0;
    }
    if(s1[i]==s2[j]){
        return dp[i][j]=1+solve(s1,s2,i+1,j+1,dp);
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
        }
    else{
        return dp[i][j]=max(solve(s1,s2,i+1,j,dp),solve(s1,s2,i,j+1,dp));
    }
}
    int longestCommonSubsequence(string text1, string text2) {
     vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size(),-1));
     return solve(text1,text2,0,0,dp);
    }
};
//tabulation,optimization
class Solution {
public:
int solve(string s1,string s2,int i,int j,vector<vector<int>>& dp){
    if(i>=s1.length()||j>=s2.length()){
           return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
        }
    if(s1[i]==s2[j]){
        return dp[i][j]=1+solve(s1,s2,i+1,j+1,dp);
    }
    
    else{
        return dp[i][j]=max(solve(s1,s2,i+1,j,dp),solve(s1,s2,i,j+1,dp));
    }
}
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0){
                dp[i][j]=0;
            }
            if(j==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(text1[i-1]==text2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
     return dp[n][m];
    }
};
