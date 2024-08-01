//solution 1
int missingK(vector < int > arr, int n, int k) {
  for(int i=0;i<n;i++){
      if(arr[i]<=k){
          k += 1;
      }
      else if(arr[i]>k){
          break;
      }
  }
  return k;
}
//solution 2 TLE
int missingK(vector < int > arr, int n, int k) {
 vector<int> missingarr(n);
 for(int i=0;i<n;i++){
     missingarr[i]=arr[i]-(i+1);
 }
 int low=0;
 int high=n-1;
 while(low<=high){
     int mid=(low+high)/2;
     if(missingarr[mid]<k){
         low=mid+1;
     }
     else if(missingarr[mid]>k){
         high=mid-1;
     }
 }
 int ans=arr[high]+(k-missingarr[high]);
 return ans;
}

//solution 2.1
/* missing=arr[high]-(high+1)
ans=arr[high]+more;
    = arr[high]+k-(arr[high]-high-1)
    =k+high+1==k+low as we kknwo after loop break low will come 1 step front in high*/

//correct 
int missingK(vector < int > arr, int n, int k) {
 
 int low=0;
 int high=n-1;
 while(low<=high){
     int mid=(low+high)/2;
     int missing=arr[mid]-(mid+1);
     if(missing<k){
         low=mid+1;
     }
     else{
         high=mid-1;
     }
 }
 return low+k;
}
