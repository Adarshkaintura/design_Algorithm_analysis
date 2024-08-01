#include<bits/stdc++.h>
int solve(vector<int> &weights,int cap){
    int day=1;
    int load=0;
    for(int i=0;i<weights.size();i++){
        if(load+weights[i]>cap){
            day+=1;
            load=weights[i];
        }else{
            load+=weights[i];
        }
    }
    return day;
}
int leastWeightCapacity(vector<int> &weights, int d)
{
    int maxi=INT_MIN;
    int sum=0;
    for(int i=0;i<weights.size();i++){
        sum += weights[i];
        maxi=max(maxi,weights[i]);
    }
    int low=maxi;
    int high=sum;
    while(low<=high){
        int mid=(low+high)/2;
        int tday=solve(weights,mid);
        if(tday<=d){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return low;
}
