class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(arr[0]>k){
            return k;
        }
        for(int i=0;i<arr.size();i++){
           if(arr[i]<=k){
            k +=1;
           }else{
             break;
           }
        }
        return k;
    }
};
//optimzed
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(arr[0]>k){
            return k;
        }
        int l=0;
        int h=arr.size()-1;
        int mis=0;
        while(l<=h){
            int m=(l+h)/2;
             mis=arr[m]-(m+1);
            if(k>mis){
                l=m+1;
            }else{
                h=m-1;
            }
        }
        mis=arr[h]-(h+1);
        return arr[h]+(k-mis);
    }
};
