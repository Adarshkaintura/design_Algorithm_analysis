class Solution {
public:

    int minMoves(vector<int>& nums) {
        int ans=0;
       int mini=INT_MAX;
       for(int i=0;i<nums.size();i++){
        mini=min(mini,nums[i]);
       }
       for(int i=0;i<nums.size();i++){
        ans+=(nums[i]-mini);
       }
       return ans;
    }
};
