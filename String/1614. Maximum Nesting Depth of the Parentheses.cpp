class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int currdepth=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                currdepth++;
               ans=max(ans,currdepth);
            }
            if(s[i]==')'){
                currdepth--;
            }

        }
        return ans;
    }
};
