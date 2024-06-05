//brute tle

int findSwapValues(int a[], int n, int b[], int m) {
       sort(a,a+n);
       sort(b,b+m);
       int nsum=0;
       int msum=0;
       for(int i=0;i<n;i++){
           nsum+=a[i];
       }
       for(int i=0;i<m;i++){
           msum+=b[i];
       }
       for(int i=0;i<n;i++){
           int an=a[i];
           int temp=nsum-an;
           for(int j=0;j<m;j++){
               
               int bm=b[j];
               int temp2=msum-bm;
               if(temp+bm==temp2+an){
                   return 1;
               }
               
           }
       }
       return -1;
    }

//optimzed;
int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        int suma=0, sumb=0;
        for(int i=0;i<n;i++) suma+=a[i];
        for(int i=0;i<m;i++) sumb+=b[i];
        
        if((suma-sumb)%2!=0) return -1;
        int target=(suma-sumb)/2;
        int i=0, j=0;
        sort(a, a+n);
        sort(b, b+m);
        while(i<n && j<m){
            int diff=a[i]-b[j];
            if(diff==target) return 1;
            else if(diff<target) i++;
            else j++;
        }
        return -1;
    }
