 int getFloor(int x,vector<int> &arr){
      int l=0;
      int h=arr.size()-1;
      int ans=-1;
      while(l<=h){
          int mid=(l+h)/2;
          if(arr[mid]==x){
              return mid;
          }
          else if(arr[mid]<x){
             ans=arr[mid];
             l=mid+1;
          }else{
              h=mid-1;
          }
      }
      return ans;
  }
   int getCeil(int x,vector<int> &arr){
      int l=0;
      int h=arr.size()-1;
      int ans=-1;
      while(l<=h){
          int mid=(l+h)/2;
          if(arr[mid]==x){
              return arr[mid];
          }
          else if(arr[mid]<x){
             
             l=mid+1;
          }else{
              ans=arr[mid];
              h=mid-1;
          }
      }
      return ans;
  }
  
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        for(int i=0;i<arr.size();i++){
            if(arr[i]==x){
                return {x,x};
            }
        }
        sort(arr.begin(),arr.end());
       int a=getFloor(x,arr);
       int b=getCeil(x,arr);
       
       return {a,b};
    }
// O(n) time complexity
 vector<int> getFloorAndCeil(int x, vector<int> &arr) {
          int floor = INT_MIN;
    int ceil = INT_MAX;

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] <= x && arr[i] > floor) {
            floor = arr[i];
        }
        if (arr[i] >= x && arr[i] < ceil) {
            ceil = arr[i];
        }
    }

    // Handle the case where no valid floor or ceiling was found
    if (floor == INT_MIN) floor = -1;
    if (ceil == INT_MAX) ceil = -1;

    return {floor, ceil};
    }
