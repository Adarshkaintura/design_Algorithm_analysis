class Solution {
public:
    string largestOddNumber(string num) {
       int n=num.length(); 
       int a=num[n-1]-'0';
       if(a%2 != 0){
        return num;
       }
       int i=0;
       for(i = n-1;i>=0;i--){
           int c=num[i]-'0';
           if(c%2!=0){
            break;
           }
       }
       if(i>=0){
        string str = num.substr(0, i + 1);;
        return str;
       }
       return "";
    }
};
