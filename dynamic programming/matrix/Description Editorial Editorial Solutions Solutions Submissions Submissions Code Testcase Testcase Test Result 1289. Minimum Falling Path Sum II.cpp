class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
       
      vector<int> prev(n),curr(n);
      for(int j=0;j<n;j++){
        prev[j]=grid[0][j];
      }
   for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int lr = INT_MAX;
                int rd = INT_MAX;
                for (int k = 0; k < n; k++) {
                    if (j != k) {
                        lr = min(lr, grid[i][j] + prev[k]);
                        rd = min(rd, grid[i][j] + prev[k]);
                    }
                }
                curr[j] = min(lr, rd);
            }
            prev = curr; 
        }
    int mini=1e8;
    for(int i=0;i<n;i++){
         mini=min(mini,prev[i]);
    }  
    return mini; 
    }
};
