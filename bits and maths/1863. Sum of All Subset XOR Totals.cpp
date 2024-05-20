//Brute;
class Solution {
public:
void solve(int i,vector<int>& nums,vector<vector<int>>& subset,vector<int> currSub){
    if(i==nums.size()){
        subset.push_back(currSub);
        return;
    }
    currSub.push_back(nums[i]);
    solve(i+1,nums,subset,currSub);
    currSub.pop_back();
    solve(i+1,nums,subset,currSub);
}
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
       int ans=0;
    vector<int> currSub;
    vector<vector<int>> subsets;

    solve(0,nums,subsets,currSub);
    for(auto& currSub:subsets){
        int Xor = 0;
        for(int num:currSub){
          Xor=Xor^num;
        }
        ans += Xor;
    }
        return ans;
    }
};

//beter
 int solve(int i, vector<int>& nums, int Xor) {
        if(i == nums.size()) {
            return Xor;
        }

        int include = solve(i+1, nums, nums[i] ^ Xor);
        int exclude = solve(i+1, nums, Xor);

        return include + exclude;
    }

    int subsetXORSum(vector<int>& nums) {
        return solve(0, nums, 0);
    }
//optimized
 int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for(int &num : nums) {
            result |= num;
        }

        return result << (n-1);
    }
