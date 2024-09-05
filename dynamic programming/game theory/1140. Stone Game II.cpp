class Solution {
public:
int alicecanget(int person,int i,int m,vector<int>& piles,int n,vector<vector<vector<int>>>& dp){
    if(i>=piles.size()){
        return 0;
    }
    if(dp[person][i][m]!=-1){
        return dp[person][i][m];
    }
    int stones=0;
    int ans;
    if(person==1){
        ans=-1;
    }else{
        ans=INT_MAX;
    }
    int a=min(2*m,n);
    for(int x=1;x <= a && (i + x - 1) < piles.size();x++){
        stones+=piles[i+x-1];
       if(person==1){//alice
        ans=max(ans,stones+alicecanget(0,i+x,max(x,m),piles,n,dp));
       }else{//bob
        ans=min(ans,alicecanget(1,i+x,max(x,m),piles,n,dp));
       }
    }
    return dp[person][i][m]=ans;
}
    int stoneGameII(vector<int>& piles) {
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(101, vector<int>(101, -1)));

        int n=piles.size();
        return alicecanget(1,0,1,piles,n,dp);
    }
};
