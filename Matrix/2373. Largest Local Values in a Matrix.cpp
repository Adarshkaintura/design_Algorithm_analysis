class Solution {
public:
int ansreturn(vector<vector<int>>& grid,int n,int m){
   int maxi=INT_MIN;
   for(int i=n;i<n+3;i++){
          for(int j=m;j<m+3;j++){
            maxi=max(grid[i][j],maxi);
          }
   }
   return maxi;
}
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> ans(n-2,vector<int>(n-2));
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                ans[i][j]=ansreturn(grid,i,j);
            }
        }
        return ans;
    }
};
