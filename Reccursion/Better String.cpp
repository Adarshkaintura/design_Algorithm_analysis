//brute force 
 void countSubsequence(string s,string temp,int n,int i,unordered_map<string,int>& mp){
      if(i==n){
          mp[temp]++;
          return;
      }
      countSubsequence(s,temp+s[i],n,i+1,mp);
      countSubsequence(s,temp,n,i+1,mp);
      return;
      
  }
    string betterString(string str1, string str2) {
        int n=str1.length();
        unordered_map<string,int> mp1;
        unordered_map<string,int> mp2;
        countSubsequence(str1,"",n,0,mp1);
        countSubsequence(str2,"",n,0,mp2);
        int a=mp1.size();
        int b=mp2.size();
        if(a>=b){
            return str1;
        }
        return str2;
    }

