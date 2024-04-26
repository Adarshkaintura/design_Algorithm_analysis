  static bool cmp(Job a,Job b){
    return a.profit > b.profit;
}
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
     
       vector<int> ans;
       int count=0;
       int prof=0;
       sort(arr,arr+n,cmp);
      
    
       vector<int> darr(n+1,-1);
       
       for(int i=0;i<n;i++){
           int currdead=arr[i].dead;
           int currprof=arr[i].profit;
           for(int k=currdead;k>0;k--){
              if(darr[k]==-1){
              count++;
              prof+=currprof;
              darr[k]=3;
              break;
          } 
           }
             
       }
      ans.push_back(count);
      ans.push_back(prof);
      return ans;
    } 
