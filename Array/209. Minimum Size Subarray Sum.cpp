class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int n = arr.size();
        int l = 0, sum = 0;
        int mini = INT_MAX;
      for(int r=0;r<n;r++){
        sum+=arr[r];
        while(sum>=target){
            mini=min(mini,r-l+1);
            sum-=arr[l];
            l++; 
        }
      }
      return (mini!=INT_MAX)?mini:0;
    }
};
