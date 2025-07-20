class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //kadane's algo
        int ansi=INT_MIN;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            if(maxi<0){
                maxi=0;
            }
            maxi+=nums[i];
            ansi=max(maxi,ansi);
        }
        return ansi;
    }
};
