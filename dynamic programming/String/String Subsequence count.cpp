int solve(string& s1,string& s2,int i,int j,vector<vector<int>>& dp,int mod){
        if(j==s2.length()){
            return 1;
        }
        if(i==s1.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            dp[i][j]=(solve(s1,s2,i+1,j+1,dp,mod)+solve(s1,s2,i+1,j,dp,mod))%mod;
        }else{
            dp[i][j]=solve(s1,s2,i+1,j,dp,mod)%mod;
        }
        return dp[i][j];
    }
    int countWays(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
       int mod=1e9+7;
        return solve(s1,s2,0,0,dp,mod)%mod;
    }
