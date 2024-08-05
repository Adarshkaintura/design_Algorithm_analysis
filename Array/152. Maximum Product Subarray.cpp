class Solution {
public:
     int maxProduct(vector<int>& nums) {
        double pref=1,suf=1;
        double maxi=INT_MIN;

        for (int i = 0; i < nums.size(); ++i) {
            int n=nums.size();
            if(pref==0)pref=1;
            if(suf==0)suf=1;
            pref=pref*nums[i];
            suf=suf*nums[n-i-1];
            maxi=max(maxi,max(pref,suf));

        }

        return (int)maxi;
    }
};
