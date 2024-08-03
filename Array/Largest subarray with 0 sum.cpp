//brute
 int maxLen(vector<int>& arr, int n) {
        int len=0;
       for(int i=0;i<n;i++){
           int sum=0;
           int l=0;
           for(int j=i;j<n;j++){
               sum+=arr[j];
                l=l+1;
               if(sum==0){
                   if(l>len){
                       len=l;
                   }
               }
           }
       }
       return len;
    }
//optimized tc O(nlogn) for hashmap
  int maxLen(vector<int>& arr, int n) {
       unordered_map<int,int> mp;
       int len=0;
       int sum=0;
       for(int i=0;i<n;i++){
         sum+=arr[i];
         if(sum==0){
             len=i+1;
         }else{
             if(mp.find(sum)==mp.end()){
                 mp[sum]=i;
             }else{
                 len=max(len,(i-mp[sum]));
             }
         }
       }
       return len;
    }
