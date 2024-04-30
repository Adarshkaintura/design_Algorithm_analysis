 int targetsum(int n,int arr[],int target,vector<vector<int>>& dp){
        if(n==0){
            return 0;
        }
        if(target==0){
            return 1;
        }
        if(dp[n-1][target]!=-1){
         return dp[n-1][target];   
        }
        if(target>=arr[n-1]){
            return dp[n-1][target]=targetsum(n-1,arr,target-arr[n-1],dp)||targetsum(n-1,arr,target,dp);
        }else{
            return dp[n-1][target]= targetsum(n-1,arr,target,dp);
        }
        
    }
    int equalPartition(int N, int arr[])
    {
       
         int sum=0;
         for(int i=0;i<N;i++){
             sum+=arr[i];
         }
         if(sum%2!=0){
             return 0;
         }
         sum/=2;
          vector<vector<int>> dp(N+1,vector<int>(sum+1,-1));
         return targetsum(N,arr,sum,dp);
    }
