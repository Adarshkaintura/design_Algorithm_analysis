#include<bits/stdc++.h>
using namespace std;
int maximumSubarraySum(vector<int>& arr,int n){
   int sum=0;
   int maxi=arr[0];
for(int i=0;i<n;i++){
    sum += arr[i];
    maxi=max(sum,maxi);
    if(sum<0){
        sum=0;
    }
    
}
return maxi;
}
int main() {
    int n;
cin>>n;
vector<int>arr(n);
for(int i=0;i<n;i++){
    cin>>arr[i];

}
  int ans=maximumSubarraySum(arr,n);
  cout<<ans;
  	return 0;
}
