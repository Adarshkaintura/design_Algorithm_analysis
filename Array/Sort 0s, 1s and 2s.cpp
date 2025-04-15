 void sort012(vector<int>& arr) {
       int zero=0;
       int one=0;
       int two=0;
       for(int i=0;i<arr.size();i++){
           if(arr[i]==0){
               zero++;
           }
           else if(arr[i]==1){
               one++;
           }
           else{
               two++;
           }
       }
       int i=0;
      while(zero--){
          arr[i]=0;
          i++;
      }
      while(one--){
          arr[i]=1;
          i++;
      }
      while(two--){
          arr[i]=2;
          i++;
      }
    }

  void sort012(vector<int>& nums) {
        int low = 0, mid = 0;
    int high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else { // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
        }
    }
    }
