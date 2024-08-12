class Solution {
public:
    string removeOuterParentheses(string s) {
       bool flag= true;
       int count=0;
       string ans="";
       for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            count++;
        }else if(s[i]==')'){
                  count--;
        }
        if(count==1 && flag==true){
            flag=false;
            continue;
        }else if(count==0 && flag==false){
            flag=true;
            continue;
        }
        ans+=s[i];
       }
        return ans;
    }
};
