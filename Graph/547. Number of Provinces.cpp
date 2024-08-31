class Solution {
public:
void dfs(unordered_map<int,vector<int>>& adj,int i,unordered_set<int>& visited){
    if(visited.find(i)!=visited.end()){
        return;
    }
    visited.insert(i);
    for(auto it:adj[i]){
        dfs(adj,it,visited);
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        unordered_set<int> visited;
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans=0;
        for(int i=0;i<adj.size();i++){
            if(visited.find(i)==visited.end()){
                ans++;
                dfs(adj,i,visited);
            }
        }
        return ans;
    }
};
