 vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
       vector<int> dist(V,INT_MAX);
       dist[S]=0;
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
       pq.push({0,S});
       while(!pq.empty()){
           int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

           
           for(auto& it:adj[u]){
               int v=it[0];
               int w=it[1];
               
               if(dist[u]+w<dist[v]){
                   dist[v]=dist[u]+w;
                   pq.push({dist[v],v});
               }
           }
       }
       return dist;
    }
