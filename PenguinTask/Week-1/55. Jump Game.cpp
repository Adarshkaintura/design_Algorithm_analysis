//TLE
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> graph(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= nums[i]; ++j) {
                if (i + j < n) {
                    graph[i].push_back(i + j);
                }
            }
        }

        // BFS traversal
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            if (current == n - 1) return true;

            for (int neighbor : graph[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return false;
    }
};

//reccursion with memoization
class Solution {
public:
 int dp[10001];
  bool solve(vector<int>& nums,int idx){
    if(idx>=nums.size()-1){
        return true;
    }
    if(dp[idx]!=-1){
        return dp[idx];
    }
    for(int i=1;i<=nums[idx];i++)
    {
        if(solve(nums,i+idx)){
            return dp[idx]=true;
        }
    }
return dp[idx]=false;
  }
    bool canJump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
       return solve(nums,0);
    }
};

//dp
bool canJump(vector<int>& nums) {
       int n=nums.size();
       vector<bool> vec(n,false);
       vec[0]=true;
       for(int i=1;i<nums.size();i++){
         int j=i-1;
           while(j>=0){
            if(vec[j]==true && nums[j]+j>=i){
                vec[i]=true;
                break;
            }
            j--;
           }
        
       }
       return vec[n-1];
    }
//optimized solution linear
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachable = 0;
        int n            = nums.size();
        
        for(int i = 0; i<n; i++) {
            if(i > maxReachable) {
                return false;
            }
            maxReachable = max(maxReachable, nums[i]+i);
        }
        
        return true;
    }
};
