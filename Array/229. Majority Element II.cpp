class Solution {
public:
        vector<int> majorityElement(vector<int>& a) {
        int n=a.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[a[i]]++;
        }
        int k=n/3;
        vector<int> ans;
        for(auto it:mp){
            if(it.second > k){
               ans.push_back(it.first);
            }
        }
        return ans;
    }
};
