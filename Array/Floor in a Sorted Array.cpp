 int findFloor(vector<long long> &v, long long n, long long x) {

       int ans=-1;
       int i=0,j=n-1;
       while(i<=j){
           int mid=(i+j)/2;
           if(v[mid]==x){
              return mid;
               
           }else if(v[mid]<x){
               ans=max(ans,mid);
               i=mid+1;
           }else{
               j=mid-1;
           }
       }
       return ans;
    }
