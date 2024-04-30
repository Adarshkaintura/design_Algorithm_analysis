 private:
    bool isbiip(int start,int V,vector<int> adj[],vector<int>& visited){
          queue<int> q;
    
    q.push(start);
    visited[start]=0;
    while (!q.empty()) {
        
            int a = q.front();
            q.pop();
            for (auto &it : adj[a]) {
                if (visited[it] == -1) {
                    visited[it] = !visited[a];
                    q.push(it);
                } else if (visited[it] == visited[a]) {
                    return false; // Not bipartite
                }
            }
        
    }
    return true; // Bipartite
    }
public:
bool isBipartite(int V, vector<int> adj[]) {
    vector<int> visited(V,-1);
    for(int i=0;i<V;i++){
     if(visited[i]==-1){
        if(isbiip(i,V,adj,visited)==false){
            return false;
        } 
     }
        
    }
    
    return true;
}
