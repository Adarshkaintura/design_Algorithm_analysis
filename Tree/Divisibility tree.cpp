int dfs(vector<int> adjlist[], vector<int>& visited, int start, int& ans) {
    visited[start] = 1;
    int cnt = 0;
    for (auto it : adjlist[start]) {
        if (!visited[it]) {
            int res = dfs(adjlist, visited, it, ans);
            if (res % 2 == 0) {
                ans++;
            } else {
                cnt += res;
            }
        }
    }
    return cnt + 1;
}

int minimumEdgeRemove(int n, vector<vector<int>>& edges) {
    vector<int> adjlist[n];
    for (auto& edge : edges) {
        adjlist[edge[0] - 1].push_back(edge[1] - 1);
        adjlist[edge[1] - 1].push_back(edge[0] - 1);
    }
    vector<int> visited(n, 0);
    int ans = 0;
    dfs(adjlist, visited, 0, ans);
    return ans;
}
