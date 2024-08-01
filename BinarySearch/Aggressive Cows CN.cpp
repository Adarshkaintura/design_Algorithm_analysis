bool checkpossible(vector<int> &stalls,int dist,int cow){
    int cntcow=1;
    int last=stalls[0];
    for(int i=1;i<stalls.size();i++){
         if(stalls[i]-last>=dist){
             cntcow++;
             last=stalls[i];
         }
        
    }
     if(cntcow>=cow){
             return true;
         }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
   int n=stalls.size();
   int low=1;
   int high=stalls[n-1]-stalls[0];
   while(low<=high){
       int mid=(high+low)/2;
       if(checkpossible(stalls,mid,k)==true){
           low=mid+1;
       }
       else{
           high=mid-1;
       }
   }
    return high;
}
