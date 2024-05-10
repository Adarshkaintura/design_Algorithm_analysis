  void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int>ds) {
        if(ind == arr.size()) {
            if(target == 0) {
                ans.push_back(ds); 
            }
            return; 
        }
        // pick up the element 
        if(arr[ind] <= target) {
            ds.push_back(arr[ind]); 
            findCombination(ind+1, target - arr[ind], arr, ans, ds); 
            ds.pop_back(); 
             while (ind + 1 < arr.size() && arr[ind] == arr[ind + 1]) {
            ind++;
        }
        }
        
        findCombination(ind+1, target, arr, ans, ds); 
        
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        findCombination(0,k,arr,ans,temp);
        return ans;
    }
