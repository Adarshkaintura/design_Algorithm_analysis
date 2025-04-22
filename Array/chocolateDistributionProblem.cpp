//brute
 int findMinDiff(vector<int>& a, int m) {
        
        sort(a.begin(),a.end());
        int mini=INT_MAX;
        int maxi=INT_MIN;
      int minidiff=INT_MAX;
      for(int i=0;i<=a.size()-m;i++){
          mini=INT_MAX;
          maxi=INT_MIN;
          for(int j=i;j<i+m && j<a.size();j++){
              mini=min(mini,a[j]);
              maxi=max(maxi,a[j]);
          }
          minidiff=min(maxi-mini,minidiff);
      }
      return minidiff;
    }
//optimized
  int findMinDiff(vector<int>& a, int m) {
        
        sort(a.begin(),a.end());
      int minidiff=INT_MAX;
      for(int i=0;i<=a.size()-m;i++){
             int newdiff=a[i+m-1]-a[i];
             minidiff=min(newdiff,minidiff);
      }
      return minidiff;
    }
};
