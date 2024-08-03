int Solution::solve(vector<int> &A, int B) {
   int ans=0;
   vector<int> prefisxor(A.size(),0);
   prefisxor[0]=A[0];
   for(int i=1;i<A.size();i++){
       prefisxor[i]=prefisxor[i-1]^A[i];
   }
   unordered_map<int,int> mp;
    for(int i=0;i<A.size();i++){
        int xr=prefisxor[i]^B;
        if(mp.find(xr)!=mp.end()){
            ans += mp[xr];
        }
      mp[prefisxor[i]]++;
      if(prefisxor[i]==B){
          ans++;
      }
    }
    return ans;
}
