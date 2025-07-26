class Solution {
public:
int count=0;
    int countArrangement(int n) {
        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            arr[i]=i+1;
        }
        solve(arr,n,0);
        return count;
    }
    void solve(vector<int>& arr,int n,int j){
        if(j==n){
            count++;
            return;
        }
        for(int i=j;i<n;i++){
            swap(arr,i,j);
            if(arr[j]%(j+1)==0 || (j+1)%arr[j]==0){
                solve(arr,n,j+1);
            }
            swap(arr,i,j);
        }
        return;
    }
    void swap(vector<int>& nums,int i,int j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
};
