class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()){
            return false;
        }
        if(s==goal){
            return true;
        }
        queue<char> q1,q2;
        for(int i=0;i<s.length();i++){
         q1.push(s[i]);
        }
        for(int i=0;i<s.length();i++){
         q2.push(goal[i]);
        }
        int k=q2.size()-1;
        while(k--){
            char ch=q2.front();
            q2.pop();
            q2.push(ch);
            if(q1==q2){
                return true;
            }
        }
        return false;
    }
};
