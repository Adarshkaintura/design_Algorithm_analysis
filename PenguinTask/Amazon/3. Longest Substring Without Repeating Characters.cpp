class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int ans=0;
        int count=0;
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            
            if(mp.find(s[i])==mp.end() || mp[s[i]]==0){
                mp[s[i]]=1;
                count++;
            }else{
                 while(s[l]!=s[i] && l<=i){
                    mp[s[l]]=0;
                    l++;
                 }
                 mp[s[l]]=0;
                 mp[s[i]]=1;
                 l++;
                count=i-l+1;
                
            } 
            ans=max(ans,count);

        }
        return ans;
    }
};
