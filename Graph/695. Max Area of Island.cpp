class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int& area, vector<vector<int>>& visited) {
       
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visited[i][j] || grid[i][j] == 0) {
            return;
        }
        
        // Mark the cell as visited
        visited[i][j] = 1;
        area += 1;

        // Explore the four possible directions
        dfs(grid, i + 1, j, area, visited); // Down
        dfs(grid, i, j + 1, area, visited); // Right
        dfs(grid, i - 1, j, area, visited); // Up
        dfs(grid, i, j - 1, area, visited); // Left
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0; // Initialize max area to 0, not INT_MIN
        int area = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        // Initialize visited matrix with 0
        vector<vector<int>> visited(m, vector<int>(n, 0));

        // Traverse each cell in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    area = 0; // Reset area for each new island
                    dfs(grid, i, j, area, visited); // Perform DFS
                    max_area = max(max_area, area); // Update max_area
                }
            }
        }
        return max_area;
    }
};
