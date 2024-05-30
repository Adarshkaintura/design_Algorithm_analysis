//brute didn't runcomplete
class Solution {
public:
bool isugly(int n){
    while(n>1){
        if(n%2==0){
        n/=2;
        }
        else if(n%3==0){
            n/=3;
        }else if(n%5==0){
            n/=5;
        }else{
            return false;
        }
    }
    if(n==1){
        return true;
    }
    return false;
}
    int nthUglyNumber(int n) {
        int count=0;
        int i=1;
        while(count<n){
           if(isugly(i)){
             count++;
           }
           i++;
        }
        return i-1;
    }
};
