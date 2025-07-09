//brute reccursive code
class Solution {
public:
    int solve(vector<vector<int>>& events,int i,int k){
        if(i>=events.size() || k<=0){
            return 0;
        }
        int skip=solve(events,i+1,k);
        int value=events[i][2];
        int end=events[i][1];
        int j=i;
        for(j=i+1;j<events.size();j++){
            if(events[j][0]>end){
                
                break;
            }
        }
   int take=value+solve(events,j,k-1);
   return max(skip,take);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());

        return solve(events,0,k);
    }
};
// memoize code
class Solution {
public:
    int solve(vector<vector<int>>& events,int i,int k,vector<vector<int>>& dp){
        if(i>=events.size() || k<=0){
            return 0;
        }
        if(dp[i][k]!=-1){
          return dp[i][k];
        }
        int skip=solve(events,i+1,k,dp);
        int value=events[i][2];
        int end=events[i][1];
        int j=i;
        for(j=i+1;j<events.size();j++){
            if(events[j][0]>end){
                
                break;
            }
        }
   int take=value+solve(events,j,k-1,dp);
   return dp[i][k]=max(skip,take);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        int n=events.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(events,0,k,dp);
    }
};
//tabulation
class Solution {
public:
    int solve(vector<vector<int>>& events,int i,int k,vector<vector<int>>& dp){
        if(i>=events.size() || k<=0){
            return 0;
        }
        if(dp[i][k]!=-1){
          return dp[i][k];
        }
        int skip=solve(events,i+1,k,dp);
        int value=events[i][2];
        int end=events[i][1];
        
        vector<int> temp={end,INT_MAX,INT_MAX};
        int j=upper_bound(events.begin()+i+1,events.end(),temp)-events.begin();
        //int j=i+1;
        // for(;j<events.size();j++){
        //     if(events[j][0]>end){
                
        //         break;
        //     }
        // }
   int take=value+solve(events,j,k-1,dp);
   return dp[i][k]=max(skip,take);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        int n=events.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(events,0,k,dp);
    }
};
