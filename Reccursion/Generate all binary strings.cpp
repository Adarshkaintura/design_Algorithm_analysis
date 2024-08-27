  void helper(int num,string s,vector<string>& ans){
        if(num==0){
            ans.push_back(s);
            return;
        }
        s=s+'0';
        helper(num-1,s,ans);
        s.pop_back();
        int l=s.length()-1;
        if(s[l]!='1'){
            s=s+'1';
            helper(num-1,s,ans);
            s.pop_back();
            return;
        }
    }
    vector<string> generateBinaryStrings(int num){
        vector<string> ans;
       if(num==0){
           return ans;
       }
       string s="";
       
       helper(num,s,ans);
       return ans;
    }
