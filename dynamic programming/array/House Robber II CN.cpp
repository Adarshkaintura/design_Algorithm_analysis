#include <bits/stdc++.h> 
long long int houseRobber(vector<int>& valueInHouse)
{
    long long prev1=valueInHouse[0];
    long long prev2=0;
    for(int i=1;i<valueInHouse.size()-1;i++){
        long long inc=prev2+valueInHouse[i];
        long long exc=prev1+0;

        long long ans=max(inc,exc);
        prev2=prev1;
        prev1=ans;

    }
    long long prev3=valueInHouse[1];
    long long prev4=0;
    for(int i=2;i<valueInHouse.size();i++){
        long long inc=prev4+valueInHouse[i];
        long long exc=prev3+0;

        long long ans=max(inc,exc);
        prev4=prev3;
        prev3=ans;
    }
    return max(prev3,prev1);
}
