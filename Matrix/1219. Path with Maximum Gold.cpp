class Solution {
public:
vector<vector<int>> direction={{-1,0},{0,-1},{1,0},{0,1}};
    int dfs(vector<vector<int>>& grid,int i,int j,int m,int n){
        if(i>=m || j>=n || i<0 || j<0 || grid[i][j]==0){
            return 0;
        }
        int originalval=grid[i][j];
        grid[i][j]=0;
        int maxgold=0;
         
         for(vector<int>& dir:direction){
            int new_i=i+dir[0];
            int new_j=j+dir[1];
            maxgold=max(maxgold,dfs(grid,new_i,new_j,m,n));

         }
        grid[i][j]=originalval;
         return originalval+maxgold;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxgold=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                      maxgold=max(maxgold,dfs(grid,i,j,m,n));
                }
            }
        }
        return maxgold;
    }
};
