class Solution {
public:
    int appendCharacters(string s, string t) {
        int l=0;
        int i=0;
        while(i<s.length() && l<t.length()){
             if(s[i]==t[l]){
                i++;
                l++;
             }else{
                i++;
             }
        }
       int n=t.length()-l;
return n;
      
    }
};
