 int findPeakElement(vector<int>& a) 
    {
       int maxi=INT_MIN;
       int i=0;
       int j=a.size()-1;
       while(i<=j){
           int mid=(i+j)/2;
           maxi=max(maxi,a[mid]);
           if(mid==0){
               i=mid+1;
           }else if(mid==a.size()-1){
               j=mid-1;
               }
        else if(a[mid]<a[mid-1]){
                   j=mid-1;
             }else{
                   i=mid+1;
               }
         
       }
       return maxi;
    }
