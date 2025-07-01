    class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
      int n=capacity.size();
      vector<int> remain(n);
      int ans=0;
      for(int i=0;i<n;i++){
        remain[i]=capacity[i]-rocks[i];
        
      }
      sort(remain.begin(),remain.end());
      for(int i=0;i<n;i++){
       if(remain[i]==0){
            ans++;
            continue;
        } 
        if(remain[i]<=additionalRocks){
          additionalRocks-=remain[i];
          remain[i]=0;
          ans++;
        }
      }
      return ans;
    }
};
