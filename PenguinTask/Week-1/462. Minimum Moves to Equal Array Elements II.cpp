class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int start=0;
        int end=nums.size()-1;
        int ans=0;
        while(start<end){
            int a=nums[start];
            int b=nums[end];
             ans+=b-a;
          start++;
          end--;
        }
        return ans;
    }
};
