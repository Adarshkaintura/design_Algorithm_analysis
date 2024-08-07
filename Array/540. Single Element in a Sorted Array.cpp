class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0;
        int h=nums.size()-1;
        while(l<h){
            int m=(l+h)/2;
              if(m%2==1){
                m=m-1;
              }
              if(nums[m]==nums[m+1]){
                l=m+2;
              }else{
                h=m;
              }

        
    }
        return nums[l];
    }
};
