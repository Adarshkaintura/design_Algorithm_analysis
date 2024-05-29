#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
 vector<vector<pair<int,int>>> intoList(vector<vector<int>>&edges,int n){
       
       vector<vector<pair<int,int>>> ans(n);
       for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
           if(edges[i][j]!=0){
            int u=i;
            int v=j;
            ans[i].push_back({j,edges[i][j]});

           }
        }
       }
       return ans;
 }
void primsalgo( vector<vector<pair<int,int>>>& adjlist,int n,int start){
    vector<int> parent(n,-1);
    vector<bool> mst(n,false);
    vector<int> key(n,INT_MAX);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start});
    while(!pq.empty()){
        int u=pq.top().second;
        mst[u]=true;
         pq.pop();
        for(auto it:adjlist[u]){
            int wt=it.second;
            int v=it.first;
            if(!mst[v] && wt<key[v]){
               key[v]=wt;
               parent[v]=u;
               pq.push({wt,v});
            }
        }
    }
   
    cout<<"the minimym wieght with vertices is :"<<endl;
    for(int i=0;i<n;i++){
        if(i!=start){
             cout<<parent[i]<<" "<<i<<" "<<key[i]<<endl;
        }
        

    }
}
int main(){
 cout<<"Enter the total number of vertices:";
 
  int n = 5; // Number of vertices
    vector<vector<int>> edges = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
  vector<vector<pair<int,int>>> adjlist=intoList(edges,n);
int start=0;

  primsalgo(adjlist,n,start);
    return 0;
}
