class Solution {
public:
    void solve(vector<int>& candidates, int target,int i,vector<vector<int>>& ans,vector<int> temp){
         if(target<0){
            return;
        }
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i==candidates.size()){
            return;
        }
        temp.push_back(candidates[i]);
        
        solve(candidates,target-candidates[i],i,ans,temp);
        temp.pop_back();
        solve(candidates,target,i+1,ans,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates,target,0,ans,temp);
        return ans;
    }
};
