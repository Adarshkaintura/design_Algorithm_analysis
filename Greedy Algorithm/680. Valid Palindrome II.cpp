class Solution {
public:
    bool checkPalin(string s){
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i]==s[j]){
             i++;
             j--;
            }else{
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
     
     
     for(int i=0;i<s.length();i++){
        string cs="";
         for(int j=0;j<s.length();j++){
            if(i!=j){
                cs+=s[j];
            }
         }
         if(checkPalin(cs)){
            return true;
         }
     }  
     return false; 
    }
};

class Solution {
public:
    bool isPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
            }
            i++;
            j--;
        }
        return true;
    }
};
