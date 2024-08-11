class Solution {
public:
   string comparestring(string s1,string s2){
    int n1=s1.length();
    int n2=s2.length();
    int i=0;
    if(s1[i]!=s2[i]){
        return "";
    }
    int n=min(n1,n2);
    while(i<n){
        if(s1[i]!=s2[i]){
            break;
        }
        i++;
    }
    return s1.substr(0,i);
   }
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==1){
            return strs[0];
        }
        string s1=strs[0];

        for(int i=1;i<n;i++){
            s1=comparestring(s1,strs[i]);
            if(s1==""){
                return "";
            }
        }
        return s1;
    }
};
