class Solution {
public:
   bool solve(vector<int>& nums,int md,int th){
    int ans=0;
        for(int i=0;i<nums.size();i++){
             double al=double(nums[i]);
             double result = (double)al/md;
             ans += ceil(result);
            if(ans>th){
                return false;
            }
        }
        return true;
        
   }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int l=1;
        int h=INT_MIN;
        for(int i=0;i<n;i++){
            h=max(h,nums[i]);
        }
        int ans=0;
        while(l<=h){
            int m=(l+h)/2;
            if(solve(nums,m,threshold)){
                ans=m;
                  h=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
};
