class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int j=0;j<m;j++){
            int prev=grid[0][j];
            for(int i=1;i<n;i++){
               if(grid[i][j]<=prev){
                ans+=prev-grid[i][j]+1;
                grid[i][j]=grid[i][j]+(prev-grid[i][j]+1);
                
               }
               prev=grid[i][j];
            }
        }
        return ans;
    }
};
