int findsole(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>& dp){
    if(j<0 ||j>=matrix[0].size()) return -1e8;
    if(i==0)return matrix[0][j];
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int u=matrix[i][j]+findsole(matrix,i-1,j,dp);
    int ld=matrix[i][j]+findsole(matrix,i-1,j-1,dp);
    int rd=matrix[i][j]+findsole(matrix,i-1,j+1,dp);
    return dp[i][j]=max(u,max(ld,rd));

}

int getMaxPathSum(vector<vector<int>> &matrix)
{
     int maxi=-1e8;
        int n=matrix.size();
       
        int m=matrix[0].size();
          vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int j=0;j<m;j++){
            maxi=max(maxi,findsole(matrix,n-1,j,dp));
        }
        return maxi;
    }
