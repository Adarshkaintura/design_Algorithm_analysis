class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        int maxi=INT_MIN;
        int val=-1;
        for(auto it:mp){
            if(it.first==it.second){
                 if(it.second>maxi){
                    maxi=it.second;
                    val=it.first;
                 }
            }
        }
        return val;
    }
};
