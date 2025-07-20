class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n=nums.size();
        set<vector<int>> st;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
           if(i>0 && nums[i-1]==nums[i]) continue;
           int l=i+1;
           int h=n-1;
           while(l<h){
         int sumi=nums[l]+nums[i]+nums[h];
            if(sumi==0){
                vector<int> temp={nums[l],nums[i],nums[h]};
                st.insert(temp);
                l++;
                h--;
            }else if(sumi>0){
                h--;
            }else{
                l++;
            }
           }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};
