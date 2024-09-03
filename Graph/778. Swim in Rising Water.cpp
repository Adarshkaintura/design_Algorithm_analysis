class Solution {
public:
vector<vector<int>> dirs = {
                {-1,0},
        {0,-1},         {0,1},
                {1, 0}
    };
    int solve(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        auto isSafe =
            [&](int x, int y) {
                return x>=0 && x<m && y>=0 &&y<n;
            };
         priority_queue<pair<int, pair<int, int>>,
                             vector<pair<int, pair<int, int>>>,
                             greater<pair<int, pair<int, int>>>>
                pq;
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        result[0][0] = heights[0][0];
        pq.push({heights[0][0], {0, 0}});

        while (!pq.empty()) {
            int diff = pq.top().first;
            auto cord = pq.top().second;
            int x = cord.first;
            int y = cord.second;
            pq.pop();
            if (x == m - 1 && y == n - 1) {
                return diff;
            }
            for(auto dir:dirs){
                int x_=x+dir[0];
                int y_=y+dir[1];
                if(isSafe(x_,y_)){
                    int newLevel=heights[x_][y_];
                    int ans=max(newLevel,diff);
                    if(result[x_][y_]>ans){
                        result[x_][y_]=ans;
                        pq.push({ans,{x_,y_}});
                    }
                }
            }
        }
         return result[m-1][n-1];
    }
    int swimInWater(vector<vector<int>>& grid) {
       return solve(grid);
    }
};
