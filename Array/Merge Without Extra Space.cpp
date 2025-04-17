//brute
   void mergeArrays(vector<int>& a, vector<int>& b) {
    int n=a.size();
    int m=b.size();
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(b[i]<a[j]){
                int temp=a[j];
                a[j]=b[i];
                b[i]=temp;
            }
        }
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    }
};
//optimized
 void mergeArrays(vector<int>& a, vector<int>& b) {
    int n=a.size();
    int m=b.size();
    
   int l=0;
   int r=n-1;
   while(l<m && r>=0){
       if(a[r]>b[l]){
           int temp=a[r];
          a[r]=b[l];
          b[l]=temp;
          l++;
          r--;
       }else{
           break;
       }
   }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    }
