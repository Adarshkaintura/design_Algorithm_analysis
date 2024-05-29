#include <bits/stdc++.h> 

using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>>& g) {
    vector<vector<pair<int, int>>> list(n + 1);
    for (int i = 0; i < m; i++) {
        int v = g[i].first.first;
        int u = g[i].first.second;
        int w = g[i].second;

        list[v].push_back({u, w});
        list[u].push_back({v, w}); // Assuming the graph is undirected
    }

    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);
    vector<int> key(n + 1, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    vector<pair<pair<int, int>, int>> ans;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        mst[u] = true;
        for (auto it : list[u]) {
            int wt = it.second;
            int v = it.first;
            if (!mst[v] && wt < key[v]) {
                key[v] = wt;
                parent[v] = u;
                pq.push({wt, v});
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        ans.push_back({{parent[i], i}, key[i]});
    }

    return ans;
}

int main() {
    // Example usage
    int n = 4;
    int m = 5;
    vector<pair<pair<int, int>, int>> edges = {
        {{1, 2}, 10},
        {{1, 3}, 5},
        {{1, 4}, 6},
        {{2, 3}, 15},
        {{3, 4}, 4}
    };

    vector<pair<pair<int, int>, int>> minSpanningTree = calculatePrimsMST(n, m, edges);

    // Printing the minimum spanning tree
    for (auto edge : minSpanningTree) {
        cout << "Edge: " << edge.first.first << " - " << edge.first.second << ", Weight: " << edge.second << endl;
    }

    return 0;
}
