class Solution {
public:
     int solve(vector<int>& weights,int m,int days){
        int l=0;
        int n=weights.size();
        int d=1;
        int temp=m;
        while(l<n){
            if(weights[l]<=m){
                m-=weights[l];
                l++;
            }else{
               m=temp;
               d++;

            }
        }
        return d;
     }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=INT_MIN;
        int h=0;
        for(int i=0;i<weights.size();i++){
            l=max(l,weights[i]);
            h+=weights[i];
        }
        int ans=0;
        while(l<=h){
            int m=(h+l)/2;
            int d=solve(weights,m,days);
            if(days>=d){
                ans=m;
               h=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
};
