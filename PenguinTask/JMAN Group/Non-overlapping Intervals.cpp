  int minRemoval(vector<vector<int>> &intervals) {
        vector<pair<int,int>> vec;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            vec.push_back({intervals[i][1],intervals[i][0]});
        }
        
        sort(vec.begin(),vec.end());
        
        int ans=0;
        int finish=vec[0].first;
        for(int i=1;i<n;i++){
            if(finish<=vec[i].second){
                finish=vec[i].first;
                
            }else{
                ans++;
            }
        }
        return ans;
    }
