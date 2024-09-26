//tle 
class Solution {
public:
    int wte=INT_MAX;
    int count=0;
    const int MOD = 1e9 + 7;
    void bfs(unordered_map<int, vector<pair<int, int>>>& adj ,int s,int d){
        queue<pair<int,int>> q;
        vector<int> dist(d+1,INT_MAX);
        q.push({s,0});
        dist[s]=0;
        while(!q.empty()){
            auto it=q.front();
            int wt=it.second;
            int a=it.first;
            
            q.pop();
            if(a==d){
              if(wt<wte){
                wte=wt;
                count=1;
              }else if(wt==wte){
                count = (count+1)%MOD;
              }
              continue;
            }
            for(auto an:adj[a]){
                
                int u=an.first;
                int w=an.second;
                if(w+wt < dist[u]){
                    dist[u]=w+wt;
                    q.push({u,w+wt});
                }else if(w+wt==dist[u]){
                      q.push({u,w+wt});
                }
                
            }

        }
  
    }
    int countPaths(int n, vector<vector<int>>& roads) {
    unordered_map<int, vector<pair<int, int>>> adj;
for(int i = 0; i < roads.size(); i++) {
    int u = roads[i][0];  // Start node
    int v = roads[i][1];  // End node
    int wt = roads[i][2]; // Weight of edge

    adj[u].push_back({v, wt});  // Add v and weight to u's adjacency list
    adj[v].push_back({u, wt});  // Add u and weight to v's adjacency list (since graph is undirected)
}
      vector<bool> visited(n,false);
    bfs(adj,0,n-1);
       return count % MOD;
    }
};
// we need to use dp or something else
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // find "NUMBER" OF SHORTEST PATHS
        int MOD = 1e9 +7;
        vector<vector<long long>> adjList[n+1];
        
        for(int i = 0 ; i < roads.size() ; i++){
            long long u = roads[i][0];
            long long v = roads[i][1];
            long long time = roads[i][2];
            
            adjList[u].push_back({v, time});
            adjList[v].push_back({u, time});
        }
        
        
        // direct dijkstra lagao and lage haath "ways" found out kro
        
        vector<long long> ways(n,0);
        ways[0] = 1;
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
        pq.push({0, 0}); // dist, node
        
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            
            long long d = front[0];
            long long currcity = front[1];
            
            for(auto &next : adjList[currcity]){
                long long nextcity = next[0];
                long long edgeWt = next[1];
                if( d + edgeWt < dist[nextcity]){
                    dist[nextcity] = d + edgeWt;
                    pq.push({ d + edgeWt , nextcity});
                    ways[nextcity] = ways[currcity]%MOD;
                }
                else if(d + edgeWt == dist[nextcity]){
                    ways[nextcity] += (ways[currcity])%MOD;   
                }
            }
        }
        
        return ways[n-1]%MOD;
        
    }
};

//my version -- 
class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int bfs(unordered_map<long long, vector<pair<long long, long long>>>& adj, int s, int d) {
        // Priority queue to keep track of (distance, node), using min-heap
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
        
        vector<long long> dist(d + 1, LLONG_MAX);  // Distance vector initialized to a large number
        vector<int> ways(d + 1, 0);  // Ways to reach each node initialized to 0
        
        dist[s] = 0;  // Distance to source is 0
        ways[s] = 1;  // There is exactly one way to reach the source
        
        q.push({0, s});  // Start from source with distance 0
        
        while (!q.empty()) {
            auto it = q.top();
            long long wt = it.first;
            long long a = it.second;
            q.pop();
            
            for (auto an : adj[a]) {
                long long u = an.first;
                long long w = an.second;
                
                // Found a shorter path to 'u'
                if (w + wt < dist[u]) {
                    dist[u] = w + wt;
                    q.push({dist[u], u});  // Push the updated distance and node into the priority queue
                    ways[u] = ways[a] % MOD;  // Set ways to reach 'u' based on 'a'
                }
                // Found another shortest path with equal distance to 'u'
                else if (w + wt == dist[u]) {
                    ways[u] = (ways[u] + ways[a]) % MOD;  // Add the number of ways to reach 'u'
                }
            }
        }
        return ways[d]%MOD;  // Return the number of ways to reach the destination
    }
    
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<long long, vector<pair<long long, long long>>> adj;
        
        // Build the adjacency list
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];  // Start node
            int v = roads[i][1];  // End node
            int wt = roads[i][2]; // Weight of edge
            
            adj[u].push_back({v, wt});  // Add v and weight to u's adjacency list
            adj[v].push_back({u, wt});  // Add u and weight to v's adjacency list (since graph is undirected)
        }
        
        return bfs(adj, 0, n - 1);  // Call BFS from node 0 to node n-1
    }
};

