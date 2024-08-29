class Solution {
public:
   int findParent(int a,vector<int>& parent){
    if(parent[a]==-1){
        return a;
    }
    return parent[a]=findParent(parent[a],parent);
   }
   void MakeUnion(int x,int y,vector<int>& parent,vector<int>& rank){
       if(rank[x]<rank[y]){
        parent[x]=y;
       }else if(rank[x]>rank[y]){
        parent[y]=x;
       }else{
        parent[y]=x;
        rank[x]++;
       }
   }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> graph;
        for(int i=0;i<points.size();i++){
            int xi=points[i][0];
            int yi=points[i][1];
            vector<int> temp;
            for(int j=i+1;j<points.size();j++){
                  int xj=points[j][0];
                  int yj=points[j][1];
                  int dist=abs(xj-xi)+abs(yj-yi);
                     vector<int> temp = {dist, i, j};  // Create new vector for each edge
               graph.push_back(temp);
            }
            
        }
     sort(graph.begin(),graph.end(),[](vector<int>& a,vector<int>& b){
        return a[0]<b[0];
     });
     int n = points.size();
   vector<int> parent(n,-1);
   vector<int> rank(n,0);
   int ans=0;
   for(int i=0;i<graph.size();i++){
      int dist=graph[i][0];
      int a=graph[i][1];
      int b=graph[i][2];
      int x=findParent(a,parent);
      int y=findParent(b,parent);
      if(x!=y){
        MakeUnion(x,y,parent,rank);
        ans+=dist;
      }
   }
   return ans;
    }
};
