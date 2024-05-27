//brute
 int helper(int i,vector<int>& a,int last){
      if(i==a.size()){
          return 0;
      }
      int take=0;
      int notake=0;
      if(a[i]-last==1 || a[i]-last==-1 ||last==-1){
          take = 1+helper(i+1,a,a[i]);
      }
      notake = helper(i+1,a,last);
      return max(notake,take);
  }
    int longestSubseq(int n, vector<int> &a) {
        int last=-1;
       
        return helper(0,a,last);
       
    }
//dp

  public:
    int longestSubseq(int n, vector<int> &a) {
        // code here
        vector<int>dp(n,0);
        
        int ans=0;
        for(int i=n-1;i>=0;i--){
            int maxi=0;
            for(int j=i+1;j<n;j++){
                if(abs(a[i]-a[j])==1){
                    maxi=max(maxi, dp[j]);
                }
            }
            dp[i]=1+maxi;
            ans=max(ans, dp[i]);
        }
        return ans;
        
    }
