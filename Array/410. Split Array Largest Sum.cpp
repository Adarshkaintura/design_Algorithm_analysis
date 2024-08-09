class Solution {
public:
int solve(vector<int>& nums,int sum){
    int sum1=0;
    int cnt=1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]+sum1 <= sum){
            sum1+=nums[i];
        }else{
            cnt+=1;
            sum1=nums[i];
        }
    }
    return cnt;
}
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n){
            return -1;
        }
        int low=0;
        int high=0;
        for(int i=0;i<nums.size();i++){
            high += nums[i];
            low=max(low,nums[i]);
        }
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
          int cnt=  solve(nums,mid);
               if(cnt<=k){
                ans=mid;
                high=mid-1;
                
               }else{
                low=mid+1;
               }
        }
        return ans;
    }
};
