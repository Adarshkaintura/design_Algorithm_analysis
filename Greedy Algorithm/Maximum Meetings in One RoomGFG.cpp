 vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<int> ans;
        vector<vector<int>> arr;
        for(int i=0;i<N;i++){
            arr.push_back({F[i],S[i],i+1});
        }
        sort(arr.begin(),arr.end());
        int prevend=-1;
        for(int i=0;i<N;i++){
            if(arr[i][1]>prevend){
              ans.push_back(arr[i][2]);
              prevend=arr[i][0];
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
