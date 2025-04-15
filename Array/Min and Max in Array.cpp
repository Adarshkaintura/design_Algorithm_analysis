 pair<int, int> getMinMax(vector<int> arr) {
       int mini=INT_MAX;
       int maxi=INT_MIN;
       for(int i=0;i<arr.size();i++){
           mini=min(arr[i],mini);
           maxi=max(arr[i],maxi);
       }
       return {mini,maxi};
    }
