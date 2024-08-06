		 int lowerBound(int arr[],int target,int n){
     int l=0;
      int h=n-1;
       int ans=-1;
      while(l<=h){
         int mid=(l+h)/2;
         if(arr[mid]<target){
            l=mid+1;
         }else {
            if(arr[mid]==target){
            ans=mid;
          
         }
           h=mid-1;
         }
}
if(ans==-1){
    return 0;
}
return ans;
 }
 int upperBound(int arr[],int target,int n){
    int l=0;
     int h=n-1;
int ans=-1;
     while(l<=h){
        int mid=(l+h)/2;
    if(arr[mid]<=target){
        if(arr[mid]==target){
            ans=mid;
        }
        l=mid+1;
    }else{
        h=mid-1;
    }
}
if(ans==-1){
    return 0;
}
return ans+1;
 }
	int count(int arr[], int n, int x) {
	    int l=lowerBound(arr,x,n);
	    int h=upperBound(arr,x,n);
	    return h-l;
	}
