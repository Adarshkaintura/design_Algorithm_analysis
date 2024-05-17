 int findPair(int n, int x, vector<int> &arr) {
       unordered_map<int,int>mp;
         int i=0,j=n-1;
         for(int i=0;i<n;i++){
            int compliment=arr[i]+x;
            int c_minum=arr[i]-x;
            if(mp.find(compliment)!=mp.end() || mp.find(c_minum)!=mp.end()){
                return 1;
            }else{
                mp[arr[i]]=1;
            }
         }
         return -1;
    }
