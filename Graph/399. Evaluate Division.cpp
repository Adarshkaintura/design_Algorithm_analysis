class Solution {
public:
  void dfs(unordered_map<string,vector<pair<string,double>>>& adj,string s,string d,double& a,double prod,unordered_set<string>& vis){
   
    if(vis.find(s)!=vis.end()){
        return;
    }
    vis.insert(s);
     if(s==d){
         a = prod;
        return;
    }
    for(auto it:adj[s]){
        string st=it.first;
        double val=it.second;
        dfs(adj,st,d,a,prod*val,vis);
    }
  }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> adj;
        for(int i=0;i<equations.size();i++){
            string s=equations[i][0];
            string d=equations[i][1];
            double wt=values[i];
            double wt2=1.0/wt;
            adj[s].push_back({d,wt});
            adj[d].push_back({s,wt2});
        }
        vector<double> ans;
        for(auto quer:queries){
            string s=quer[0];
            string d=quer[1];

            double a=-1.0;
            double prod=1.0;
            if(adj.find(s)!=adj.end()){
                unordered_set<string> visited;
                 dfs(adj,s,d,a,prod,visited);
            }
          ans.push_back(a); 
        }
        return ans;
    }
};
