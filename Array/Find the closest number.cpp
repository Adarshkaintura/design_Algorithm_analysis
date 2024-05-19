int findClosest( int n, int k,int arr[]) 
    { 
        int ans=arr[0];
       int l=0;
       int h=n-1;
       while(l<=h){
           int mid=(l+h)/2;
           if (abs(k - arr[mid]) < abs(k - ans)) {
            ans = arr[mid];
        } else if (abs(k - arr[mid]) == abs(k - ans) && arr[mid] > ans) {
            ans = arr[mid];
        }
           if(arr[mid]==k){
               return arr[mid];
           }
           else if(arr[mid]>k){
               h=mid-1;
           }else{
               l=mid+1;
           }
           
           
       }
       return ans;
       
    } 
