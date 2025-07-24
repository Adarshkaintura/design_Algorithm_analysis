//brute 
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ans = LLONG_MAX;
        for(int i = 0; i < nums.size(); i++) {
            long long temp = 0;
            for(int j = 0; j < nums.size(); j++) {
                long long a = abs(nums[i] - nums[j]);
                a *= cost[j];
                temp += a;
            }
            ans = min(ans, temp);
        }
        return ans;
    }
};

//OPMITIZED
class Solution {
public:
long long sum(vector<int>& nums,vector<int>& cost,int target){
    long long ans=0;
    for(int i=0;i<nums.size();i++){
        ans+= (long long)abs(nums[i]-target)*cost[i];
    }
    return ans;
}
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ans = INT_MAX;
        int n=nums.size();
        int left = *min_element(nums.begin(), nums.end());
        int right= *max_element(nums.begin(),nums.end());

        while(left<=right){
        int mid=left+(right-left)/2;
        long long ans1=sum(nums,cost,mid);
        long long ans2=sum(nums,cost,mid+1);
        
        ans=min(ans1,ans2);
        if(ans1<ans2){
            right=mid-1;
        }else{
            left=mid+1;
        }
        }
        if(ans==INT_MAX){
            return 0;
        }
        return ans;
    }
};
