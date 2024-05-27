 bool dfs(vector<bool>& visited,vector<vector<int>>& adjlist,int src,int parent){
        visited[src]=true;
        for(auto it:adjlist[src]){
            if(visited[it]==false){
                if(dfs(visited,adjlist,it,src)==true){
                    return true;
                }
            }else if(it!=parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
       vector<vector<int>> adjlist(V);
       for(int i=0;i<V;i++){
          for(auto it:adj[i]){
              adjlist[i].push_back(it);
           
          }
       }
       vector<bool> visited(V,false);
       for(int i=0;i<V;i++){
           if(visited[i]==false){
               if(dfs(visited,adjlist,i,-1)==true){
                   return true;
               }
           }
       }
       return false;
    }
