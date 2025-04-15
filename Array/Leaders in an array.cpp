#include <bits/stdc++.h> 
vector<int> findLeaders(vector<int> &arr, int n) {
    vector<int> ans;
    int flag=1;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]>=arr[i]){
                flag=0;
                break;
            }
        }
     if(flag){
         ans.push_back(arr[i]);
     }
     flag=1;
    }
    return ans;
}
