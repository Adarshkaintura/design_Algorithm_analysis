//brute
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
     vector<int> ans;
     
     for(int i=0;i<nums.size()-k+1;i++){
         int maxi=INT_MIN;
         for(int j=i;j<i+k;j++){
              maxi=max(maxi,nums[j]);
         }
         ans.push_back(maxi);
     }
return ans;
}
