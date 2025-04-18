class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx=-1;
        int n=nums.size();
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                idx=i-1;
                break;
            }
        }
        if(idx!=-1){
            for(int i=n-1;i>idx;i--){
                if(nums[idx]<nums[i]){
                    int temp=nums[idx];
                    nums[idx]=nums[i];
                    nums[i]=temp;
                    break;
                }
            }
            reverse(nums.begin()+idx+1,nums.end());

        }else{
            reverse(nums.begin(),nums.end());

        }
       
    }
};
