//brute
#include<bits/stdc++.h>
int solve(vector<int> &arr,int pages){
    int stud=1,stupages=0;
    for(int i=0;i<arr.size();i++){
        if(stupages+arr[i]<=pages){
            stupages += arr[i];
              
        }else{
            stud++;
            stupages=arr[i];
        }
    }
    return stud;
}
int findPages(vector<int>& arr, int n, int m) {
    int low=INT_MIN;
    int high=0;
  for(int i=0;i<n;i++){
   low=max(low,arr[i]);
   high += arr[i];
  }

  for(int pages=low;pages<=high;pages++){
      int cntstu=solve(arr,pages);
      if(cntstu==m){
          return pages;
      }
  }
  return -1;
}
//optimized
#include<bits/stdc++.h>
int solve(vector<int> &arr,int pages){
    int stud=1,stupages=0;
    for(int i=0;i<arr.size();i++){
        if(stupages+arr[i]<=pages){
            stupages += arr[i];
              
        }else{
            stud++;
            stupages=arr[i];
        }
    }
    return stud;
}
int findPages(vector<int>& arr, int n, int m) {
    if(m>n)return -1;
    int low=INT_MIN;
    int high=0;
  for(int i=0;i<n;i++){
   low=max(low,arr[i]);
   high += arr[i];
  }
int ans;
  while(low<=high){
      int mid=(low+high)/2;
      int cntstu=solve(arr,mid);
      if (cntstu <= m) {
          ans=mid;
            high=mid-1;
      }else{
          low=mid+1;
      }
  }
  return ans;;
}
