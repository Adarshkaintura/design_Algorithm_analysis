#include<algorithm>
void reverseArray(vector<int>& arr, int m) {
   int l=m+1,r=arr.size()-1;
   int temp=0;
   while(l<r){
    temp=arr[l];
    arr[l]=arr[r];
    arr[r]=temp;
    l++;
    r--;
   }
}
