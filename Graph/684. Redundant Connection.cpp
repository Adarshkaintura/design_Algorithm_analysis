class Solution {
public:
int findParent(int a,vector<int>& parent){
    if(parent[a]==-1){
        return a;
    }
    return parent[a]=findParent(parent[a],parent);
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

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       vector<int> rank(edges.size()+1,1);
       vector<int> parent(edges.size()+1,-1);
       vector<int> ans(2);
       for(auto it:edges){
        int a=findParent(it[0],parent);
        int b=findParent(it[1],parent);
          if(a!=b){
            unionTree(a,b,parent,rank);
          }else{
            ans[0]=it[0];
            ans[1]=it[1];
          }
       }
       return ans;
    }
};
