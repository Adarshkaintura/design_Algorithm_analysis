#Brute
class Solution {
public:
double ans=1;
    double myPow(double x, int n) {
    if(n==0){
        return ans;
    }
    if(n<0){
          ans *= 1/(x);
          return myPow(x,n+1);
    }else{
          ans=ans*x;
    return myPow(x,n-1);
    }
    
    }
};

//another approach with few changes 
class Solution {
public:
double ans=1;
    double myPow(double x, int n) {
        if(x==1){
            return x;
        }
      if(n>=(INT_MAX/10)){
        return x;
      }else if(n<=(INT_MIN/10)){
        if(x==-1){
            return 1;
        }
        return 0;
      }
    if(n==0){
        return ans;
    }
    if(n<0){
          ans *= 1/(x);
          return myPow(x,n+1);
    }else{
          ans=ans*x;
    return myPow(x,n-1);
    }
    
    }
};
