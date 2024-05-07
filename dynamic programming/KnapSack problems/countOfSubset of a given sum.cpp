//direct tabulation method i don't why my reccursive code is not working
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr = {1,2,3,3};
 
   
    vector<vector<int>> dp(arr.size() + 1, vector<int>(7));
    for(int i=0;i<5;i++){
        for(int j=0;j<7;j++){
             if(i==0){
                dp[i][j]=0;
             }
             if(j==0){
                dp[i][j]=1;
             }
        }
    }

   for(int i = 1; i <= 4; i++) {
    for(int j = 0; j <= 6; j++) {
        if (arr[i-1] <= j) {
            dp[i][j] = dp[i-1][j] + dp[i-1][j - arr[i-1]];
        } else {
            dp[i][j] = dp[i-1][j];
        }
    }
}

    cout << "The total count is: " << dp[arr.size()][6];
    return 0;
}
