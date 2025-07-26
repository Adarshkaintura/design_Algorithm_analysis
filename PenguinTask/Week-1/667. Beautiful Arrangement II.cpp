class Solution {
public:
    void reversearr(vector<int>& nums,int idx){
        int l=idx;
        int r=nums.size()-1;
        while(l<r){
            int temp=nums[l];
            nums[l]=nums[r];
            nums[r]=temp;
            l++;
            r--;
        }
    }
    vector<int> constructArray(int n, int k) {
       vector<int> arr(n);
       for(int i=0;i<n;i++){
        arr[i]=i+1;
       }
       if(k==1){
        return arr;
       } 
      for(int i=1;i<k;i++){
         reversearr(arr,i);
      }
      return arr;
    }
};
