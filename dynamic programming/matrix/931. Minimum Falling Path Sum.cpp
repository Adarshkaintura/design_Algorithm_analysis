class Solution {
public:
// int findsole(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>& dp){
//     if(j<0 ||j>=matrix[0].size()) return 1e8;
//     if(i==0)return matrix[0][j];
//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }
//     int u=matrix[i][j]+findsole(matrix,i-1,j,dp);
//     int ld=matrix[i][j]+findsole(matrix,i-1,j-1,dp);
//     int rd=matrix[i][j]+findsole(matrix,i-1,j+1,dp);
//     return dp[i][j]=min(u,min(ld,rd));

// }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini=1e8;
        int n=matrix.size();
        int m=matrix[0].size();

       vector<vector<int>> dp(n, vector<int>(m, 0));
       for(int j=0;j<m;j++){
             dp[0][j]=matrix[0][j];   
       }
       for(int i=1;i<n;i++){
         for(int j=0;j<m;j++){
            int u=matrix[i][j]+dp[i-1][j];
            int ld=matrix[i][j];
            if(j-1>=0) ld+=dp[i-1][j-1];
            else ld+=1e8;
    
            int rd=matrix[i][j];
            if(j+1<m) rd+=dp[i-1][j+1];
            else rd+=1e8;
             dp[i][j]=min(u,min(ld,rd));
            //  int min_prev = dp[i - 1][j];
            //     if (j - 1 >= 0) min_prev = min(min_prev, dp[i - 1][j - 1]);
            //     if (j + 1 < m) min_prev = min(min_prev, dp[i - 1][j + 1]);
                
            //     dp[i][j] = matrix[i][j] + min_prev;
         }
       }

        for(int j=0;j<m;j++){
            mini=min(mini,dp[n-1][j]);
        }
        return mini;
    }
};
