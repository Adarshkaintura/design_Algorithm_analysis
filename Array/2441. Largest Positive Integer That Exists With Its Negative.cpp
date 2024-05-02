//brute foce
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int maxi=-1;
       for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums.size();j++){
            if(i!=j){
                if(nums[i]<0){
             if(abs(nums[i])==abs(nums[j])){
                if(maxi<nums[j]){
                    maxi=nums[j];
                }
             }
                }
       
            }
             
        }
       } 
       
       return maxi;
    }
};
//optimized
class Solution {
public:
  int findMaxK(std::vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        int maxK =numeric_limits<int>::min();
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == 0) {
                maxK = std::max(maxK, nums[right]);
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
        return maxK != numeric_limits<int>::min() ? maxK : -1;  // If no such pair found
    }
};
