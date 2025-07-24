class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int idx=-1;
        int n=arr.size()-1;
        for(int i=n;i>0;i--){
            if(arr[i-1]<arr[i]){
                idx=i-1;
                break;
            }
        }
         if (idx == -1){
              reverse(arr.begin(),arr.end());
            return;
         } 
         if (idx != -1) {
            int idxx = -1;
            for (int i = n; i >=idx; i--) {
                if (arr[i] > arr[idx]) {
                    idxx = i;
                    break;
                }
            }
            swap(arr[idx], arr[idxx]);
        }
  reverse(arr.begin()+idx+1,arr.end());
    }
};
