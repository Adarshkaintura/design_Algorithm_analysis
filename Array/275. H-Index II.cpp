class Solution {
public:
    int hIndex(vector<int>& citations){
       int l=0;
       int h=citations.size()-1;
       int n=h+1;
       int ans=0;
       while(l<=h){
        int mid=(l+h)/2;
        if(citations[mid]>=n-mid){
            h=mid-1;
            ans=n-mid;
        }else{
            l=mid+1;
        }
       }
        return ans;
    }
};
