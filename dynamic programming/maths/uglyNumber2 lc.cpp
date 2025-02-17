//tc O(n)
class Solution {
public:
    int nthUglyNumber(int n) {
     vector<int> dp(n);
     dp[0]=1;
     int i=0,j=0,k=0;
     int mini=INT_MIN;
     for(int ik=1;ik<n;ik++){
         int i2=dp[i]*2;
         int i3=dp[j]*3;
         int i5=dp[k]*5;
         mini=min(i2,min(i3,i5));

         if(mini==i2) i++;
         if(mini==i3) j++;
         if(mini==i5) k++;

         dp[ik]=mini;

     } 
     return dp[n-1];  
    }
};
