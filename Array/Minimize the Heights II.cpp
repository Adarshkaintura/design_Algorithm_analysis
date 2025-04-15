//brute
 int diffminmax(vector<int>& arr){
      int mini=INT_MAX;
      int maxi=INT_MIN;
      int n=arr.size();
      for(int i=0;i<n;i++){
          mini=min(mini,arr[i]);
          maxi=max(maxi,arr[i]);
      }
      return maxi-mini;
  }
  void solve(vector<int>& arr,int i,int& mini,int k){
      if(i>=arr.size()){
          mini=min(mini,diffminmax(arr));
          return;
      }
      arr[i]+=k;
      solve(arr,i+1,mini,k);
      arr[i]-=k;
      int a=arr[i]-k;
      if(a<0){
          return;
      }
      arr[i]=a;
      solve(arr,i+1,mini,k);
      arr[i]+=k;
  }
    int getMinDiff(vector<int> &arr, int k) {
      int mini=INT_MAX;
      solve(arr,0,mini,k);
      return mini;
    }
///optimzied
