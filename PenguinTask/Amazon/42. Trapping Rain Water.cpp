class Solution {
public:
    int trap(vector<int>& height) {
  vector<int> larr(height.size());
  vector<int> rarr(height.size());
  
  int n=height.size();
  int maxi=height[0];
  larr[0]=height[0];
  for(int i=1;i<n;i++){
   
    maxi=max(maxi,height[i]);
    larr[i]=maxi;
  }
  maxi=height[n-1];
  rarr[n-1]=maxi;
  for(int i=n-2;i>=0;i--){
    maxi=max(maxi,height[i]);
    rarr[i]=maxi;
  }
  int ans=0;
  for(int i=0;i<n;i++){
    int a=min(larr[i],rarr[i]);
    ans+=a-height[i];
  }      
  return ans;
    }
};
