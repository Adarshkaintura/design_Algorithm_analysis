#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//dp version is same and easy 
 int countWays(int target,vector<int>& coins,int i){
    if(i==coins.size()){
        if(target==0){
            return 1;
        }else{
            return 0;
        }
    }
    if(target==0){
        return 1;
    }
    
    if(target<coins[i]){
      return countWays(target,coins,i+1);
    }else{
        return countWays(target-coins[i],coins,i)+countWays(target,coins,i+1);
    }
 }
int main() {
    int numCoins;
    cout << "Enter the number of available types of coins: ";
    cin >> numCoins;

    vector<int> coins(numCoins);
    cout << "Enter the values of available types of coins: ";
    for (int i = 0; i < numCoins; ++i) {
        cin >> coins[i];
    }

    int N;
    cout << "Enter the value for which you need to find the sum: ";
    cin >> N;

    int ways = countWays(N, coins,0);
    cout << "Number of ways to make the sum " << N << ": " << ways << endl;

    return 0;
}
