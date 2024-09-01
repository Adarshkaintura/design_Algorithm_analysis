class Solution {
public:
    int findParent(int a, vector<int>& parent) {
        if (parent[a] == -1) {
            return a;
        }
        return parent[a] = findParent(parent[a], parent);
    }
    void unionTree(int a, int b, vector<int>& parent, vector<int>& rank) {
        int parentA = findParent(a, parent);
        int parentB = findParent(b, parent);

        if (parentA != parentB) {
            // Union by rank
            if (rank[parentA] > rank[parentB]) {
                parent[parentB] = parentA;
            } else if (rank[parentA] < rank[parentB]) {
                parent[parentA] = parentB;
            } else {
                parent[parentB] = parentA;
                rank[parentA]++;
            }
        }
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> bl(2, -1);
        vector<int> visited(edges.size() + 1, -1);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            if (visited[v] != -1) {
                bl[0] = i;
                bl[1] = visited[v];
                break;
            }
            visited[v] = i;
        }

        vector<int> ans(2);
        vector<int> rank(edges.size() + 1, 1);
        vector<int> parent(edges.size() + 1, -1);
        if (bl[0] == -1) {

            for (auto it : edges) {
                int a = findParent(it[0], parent);
                int b = findParent(it[1], parent);
                if (a != b) {
                    unionTree(a, b, parent, rank);
                } else {
                    ans[0] = it[0];
                    ans[1] = it[1];
                    return ans;
                }
            }
        }
        ans[0] = edges[bl[0]][0];
        ans[1] = edges[bl[0]][1];

        int i = 0;
        for (auto it : edges) {
            if (i == bl[0]) {
                i++;
                continue;
            }
            i++;
            int a = findParent(it[0], parent);
            int b = findParent(it[1], parent);
            if (a != b) {
                unionTree(a, b, parent, rank);
            } else {
                ans[0] = edges[bl[1]][0];
                ans[1] = edges[bl[1]][1];
                return ans;
            }
        }
        return ans;
    }
};
