class Solution {
public:
    bool isIsomorphic(string s, string t) {
          int n1=s.length();
        int n2=t.length();
        if(n1!=n2){
            return false;
        }
        unordered_map<char,char> ap,dp;
        for(int i=0;i<n1;i++){
            char ch1=s[i];
            char ch2=t[i];
            if(ap.find(ch1)!=ap.end() && ap[ch1]!=ch2 ||dp.find(ch2)!=dp.end() && dp[ch2]!=ch1){
                return false;
            }
            ap[ch1]=ch2;
            dp[ch2]=ch1;
        }
      return true;
    }
};
