 int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<pair<int,int>> vec;
        for(int i=0;i<start.size();i++){
            vec.push_back({end[i],start[i]});
        }
        
        sort(vec.begin(),vec.end());
        
        int maxans=1;
        int finish=vec[0].first;
        for(int i=1;i<start.size();i++){
            if(finish<vec[i].second){
                finish=vec[i].first;
                maxans++;
            }
        }
        return maxans;
    }
