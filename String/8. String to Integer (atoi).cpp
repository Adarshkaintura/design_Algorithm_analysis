class Solution {
public:
    int myAtoi(string s) {
       int sign=1;
        
        int result=0;
        int k=0;
        while(s[k]==' '){
            k++;
        }
        if(s[k]=='-'){
            sign=-1;
            k++;
        }else if(s[k]=='+'){
            k++;
        }
for(int i=k;i<s.length();i++){
    int a=s[i]-'0';
    if(a>=0 && a<=9){
        
        if(result>(INT_MAX-a)/10){
            return (sign==1)?INT_MAX:INT_MIN;
        }
        result= (result*10)+a;
    }else{
        break;
    }
}
return sign*result;
    }
};
