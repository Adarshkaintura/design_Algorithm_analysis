class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int t=nums[0];
        int h=nums[0];
       do{
        t=nums[t];
        h=nums[nums[h]];
       }while(t!=h);
       t=nums[0];
       while(t!=h){
        t=nums[t];
        h=nums[h];
       }
       return t;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& arr) {
      sort(arr.begin(),arr.end());
      for(int i=0;i<arr.size()-1;i++){
        if(arr[i]==arr[i+1]){
            return arr[i];
        }
      }
      return 0;
    }
};
