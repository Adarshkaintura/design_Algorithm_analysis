class Solution {
public:
    int reccurAtoi(string s,int i,int ans,int sign){
        int a=s[i]-'0';
        if(a>=0 && a<=9){
            if(ans>(INT_MAX/10) || ans==(INT_MAX/10) && a>(INT_MAX%10)){
                ans=(sign==-1)?INT_MIN:INT_MAX;
                return ans;
            }else{
                ans=(ans*10)+a;
                return reccurAtoi(s,i+1,ans,sign);
            }   
        }else{
            return sign*ans;
        }
    }
    int myAtoi(string s) {
        int i=0;
        int ans=0;
     while(s[i]==' '){
        i++;
     }
     if(i==s.length()){
        return ans;
     }
     int sign=1;
     if(s[i]=='-'){
          sign=-1;
          i++;
     }else if(s[i]=='+'){
       i++;  
     }
     return reccurAtoi(s,i,ans,sign);
    }
};
