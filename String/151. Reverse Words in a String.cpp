class Solution {
public:
    string reverseWords(string s) {
    reverse(s.begin(),s.end());
    int i=0;
    int left=0;
    int right=0;
    int n=s.length();
    while(i<n){
       while(i<n && s[i]==' '){
        i++;
       }
       if(i==n){
        break;
       }
       while(i<n && s[i]!=' '){
        s[right++]=s[i++];
       }
reverse(s.begin()+left,s.begin()+right);
       s[right++]=' ';
       left=right;
       i++;
    }
    s.resize(right-1);
    return s;
    }
};
