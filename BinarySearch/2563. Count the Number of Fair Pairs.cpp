class Solution {
public:
//two sum approach
   long long solve(vector<int>& nums,int target){
    long long cnt=0;
    int i=0,j=nums.size()-1;
    while(i<j){
        if(nums[i]+nums[j]<=target){
            cnt+=j-i;
            i++;
        }else{
         j--;
        }
    }
    return cnt;
   }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
       sort(nums.begin(),nums.end());
       return solve(nums,upper)-solve(nums,lower-1);
    }
};
