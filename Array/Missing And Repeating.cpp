  vector<int> findTwoElement(vector<int> arr, int n) {
        long long N=n;
      long long sn=(N*(N+1))/2;
        long long s2n=(N*(N+1)*((2*N)+1))/6;
        long long si=0,s2i=0;
        for(int i=0;i<n;i++){
           si += arr[i];
         s2i += (long long)arr[i]*(long long)arr[i];
        }
        long long val1=si-sn;
        long long val2=s2i-s2n;
                val2=val2/val1;
        
     
        long long x=(val1+val2)/2;
        long long y=x-val1;
        
    return {(int)x,(int)y};
        
    }
