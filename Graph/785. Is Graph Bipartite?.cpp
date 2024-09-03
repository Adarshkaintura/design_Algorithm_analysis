class Solution {
public:
    int isParent(int x, vector<int>& parent) {
        if (parent[x] == -1) {
            return x;
        }
        return parent[x] = isParent(parent[x], parent);
    }
    void makeUnion(int x, int y, vector<int>& parent, vector<int>& rank) {
        x = isParent(x, parent);
        y = isParent(y, parent);
        if (x != y) {
            if (rank[x] > rank[y]) {
                parent[y] = x;
            } else if (rank[x] < rank[y]) {
                parent[x] = y;
            } else {
                parent[x] = y;
                rank[y]++;
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> parent(n, -1);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++) {
            for (auto it : graph[i]) {
                int x = isParent(i, parent);
                int y = isParent(it, parent);
                if (x == y) {
                    return false;
                }
                makeUnion(graph[i][0], it, parent, rank);
            }
        }
        return true;
    }
};
