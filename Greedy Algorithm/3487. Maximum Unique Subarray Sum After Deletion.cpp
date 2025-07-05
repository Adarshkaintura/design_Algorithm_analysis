class Solution {
public:
    int maxSum(vector<int>& nums) {
       int sum=0;
        unordered_map<int,int> mp;
        for(auto num:nums){
            if(num>=0 && mp.find(num)==mp.end()){
               mp[num]=1;
               sum+=num;
            }
           
        }
        if(mp.size()<=0){
            int maxi=INT_MIN;
            for(int i=0;i<nums.size();i++){
                maxi=max(maxi,nums[i]);
            }
            return maxi;
        }
return sum;
    }
};
