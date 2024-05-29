#include<bits/stdc++.h>
void make_set(vector<int>& parent,vector<int>& rank,int n){
    for(int i=0;i<n;i++){
      parent[i]=i;
      rank[i]=0;
    }
}
int findParent(vector<int>& parent,int i){
  if(parent[i]==i){
    return parent[i];
  }
  return parent[i]=findParent(parent,parent[i]);
}
bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[2] < b[2];
}

void union_set(vector<int>& parent,vector<int>& rank,int u,int v){
  u=findParent(parent,u);
  v=findParent(parent,v);
  if(rank[u]<rank[v]){
    parent[u]=v;
  }else if(rank[v]<rank[u]){
    parent[v]=u;
  }else{
    parent[v]=u;
    rank[u]++;
  }
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
vector<int> parent(n);
vector<int> rank(n);
make_set(parent,rank,n);
int maxwt=0;
sort(edges.begin(),edges.end(),cmp);
for(int i=0;i<edges.size();i++){
  int u=findParent(parent,edges[i][0]);
  int v=findParent(parent,edges[i][1]);
int wt=edges[i][2];
  if(u!=v){
    union_set(parent,rank,u,v);
   maxwt+=wt;
  }
}
return maxwt;
}
