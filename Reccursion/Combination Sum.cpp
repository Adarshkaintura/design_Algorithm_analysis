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
            findCombination(ind, target - arr[ind], arr, ans, ds); 
            ds.pop_back(); 
             while (ind + 1 < arr.size() && arr[ind] == arr[ind + 1]) {
            ind++;
        }
        }
        
        findCombination(ind+1, target, arr, ans, ds); 
        
    }

    vector<vector<int>> combinationSum12(vector<int>& candidates, int target) {
        vector<vector<int>> ans; 
        vector<int> ds; 
        findCombination(0, target, candidates, ans, ds); 
        return ans; 
    }

    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        sort(A.begin(),A.end());
        return combinationSum12(A,B);
    }
