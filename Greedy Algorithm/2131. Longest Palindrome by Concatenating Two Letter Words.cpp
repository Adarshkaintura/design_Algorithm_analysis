class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        int result=0;
        bool dublicateUser=false;
        string str;
        for(auto it:words){
            str=it;
            reverse(str.begin(),str.end());
            if(str!=it){ //ab - ba
              if(mp[str]>0 && mp[it]>0){
                mp[str]--;
                mp[it]--;
                result+=4;
              }
            }else{
                if(mp[str]>=2){
                    mp[str]-=2;
                    result+=4;
                }else if(mp[str]==1 && !dublicateUser){
                    dublicateUser=true;
                    mp[str]--;
                    result+=2;
                }
            }
        }
        return result;
    }
};
