int findKRotation(vector<int> &arr) {
        int l=0;
        int h=arr.size()-1;
        while(l<h){
            int m=(l+h)/2;
        
            if(arr[m]<arr[h]){
                h=m;
            }else{
               l=m+1;
            }
        }
        return h;
    }
