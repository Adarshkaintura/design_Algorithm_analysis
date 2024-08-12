class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        vector<int> sortedarr;
        for(auto it:mp){
            sortedarr.push_back(it.first);
        }
        sort(sortedarr.begin(),sortedarr.end(),[&](char a,char b){
            return mp[a]>mp[b];
        });
        s="";
        for(auto ch:sortedarr){
           s+=string(mp[ch],ch);
        }
        return s;
    }
};
