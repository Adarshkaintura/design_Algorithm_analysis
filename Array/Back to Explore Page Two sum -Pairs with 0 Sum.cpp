//brute force
vector<vector<int>> getPairs(vector<int>& arr) {
        vector<vector<int>> ans;
        unordered_map<int,int> mp;
       for(int i=0;i<arr.size();i++){
           for(int j=i+1;j<arr.size();j++){
               if((arr[i]==0  && arr[j]==0) || (arr[i]!=arr[j] && arr[i]+arr[j]==0)){
                  if(mp.find(arr[i])==mp.end() && mp.find(arr[j])==mp.end()){
                 int mini=min(arr[i],arr[j]);
                 int maxi=max(arr[i],arr[j]);
                 ans.push_back({mini,maxi});
                  mp[arr[i]]=1;
                  mp[arr[j]]=1;
                  }
               }
           }
       }
       sort(ans.begin(),ans.end());
       return ans;
    }
//optimized
//two pointer approach easy one please remember it 
  vector<vector<int>> getPairs(vector<int>& arr) {
       vector<vector<int>> ans;
       sort(arr.begin(),arr.end());
       int l=0,r=arr.size()-1;
       while(l<r){
           if(arr[l]+arr[r]==0){
               ans.push_back({arr[l],arr[r]});
               int a=arr[l];
               int b=arr[r];
               while(a==arr[l] && l<r) l++;
               while(b==arr[r] && r>l) r--;
           }else if(arr[l]+arr[r]>0){
               r--;
           }else{
               l++;
           }
       }
       return ans;
    }
