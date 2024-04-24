int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++){
         arr.push_back({end[i], start[i]});
        }
        sort(arr.begin(),arr.end());
         int prevend=arr[0].first;
         
         int count=1;
         for(int i=1;i<n;i++){
             if(arr[i].second>prevend){
                 count++;
                 prevend=arr[i].first;
             }
             
         }
         return count;
    }
