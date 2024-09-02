class Solution {
public:
    // Function to find the parent of an element using path compression
    int findParent(int i, vector<int>& parent) {
        if (parent[i] == -1) {
            return i;
        }
        return parent[i] = findParent(parent[i], parent);
    }
    
    // Function to perform union of two sets
    void MakeUnion(vector<int>& ds, int a, int b) {
        int parentA = findParent(a, ds);
        int parentB = findParent(b, ds);
        if (parentA != parentB) {
            ds[parentA] = parentB;  // Union by assigning one parent to another
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> mp;  // Map to store email to index mapping
        vector<int> ds(n, -1);  // Disjoint set with all elements initialized to -1

        // Build the union-find structure for accounts
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {  // Start from 1 to skip the name
                string email = accounts[i][j];
                if (mp.find(email) == mp.end()) {
                    mp[email] = i;  // Map email to the current account index
                } else {
                    MakeUnion(ds, mp[email], i);  // Union the sets of accounts sharing this email
                }
            }
        }

        // Create a mapping from parent to emails
        vector<vector<string>> temp(n);
        for (auto it : mp) {
            int parentIdx = findParent(it.second, ds);
            temp[parentIdx].push_back(it.first);
        }

        // Prepare the final result
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (!temp[i].empty()) {
                vector<string> mergedAccount;
                mergedAccount.push_back(accounts[i][0]);  // Add the name
                sort(temp[i].begin(), temp[i].end());  // Sort emails lexicographically
                mergedAccount.insert(mergedAccount.end(), temp[i].begin(), temp[i].end());
                ans.push_back(mergedAccount);
            }
        }
        
        return ans;
    }
};
