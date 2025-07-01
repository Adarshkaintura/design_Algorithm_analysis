class Solution {
public:
 
    int brokenCalc(int startValue, int target) {
        int t=startValue;
        int s=target;
 int ans=0;
        while(s!=t){
            if(s%2==0 && s>t){
               ans++;
                s=s/2;
            }else{
                s+=1;
                ans++;
            }
        }
     return ans;   
    }
};
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if(startValue >= target)
            return startValue-target;
        
        //even
        if(target%2 == 0) {
            return 1 + brokenCalc(startValue, target/2);
        }
        
        
        return 1 + brokenCalc(startValue, target+1);
    }
};
