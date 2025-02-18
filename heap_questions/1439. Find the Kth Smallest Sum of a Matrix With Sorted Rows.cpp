

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        
        // Min Heap to store (sum, index vector)
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> minHeap;
        
        // Set to avoid duplicate states
        set<vector<int>> seen;
        
        // Initial state: sum of first column elements, index vector (0,0,...,0)
        vector<int> indices(m, 0);
        int sum = 0;
        for (int i = 0; i < m; ++i) sum += mat[i][0];
        
        minHeap.push({sum, indices});
        seen.insert(indices);
        
        // Extract k times from heap
        for (int count = 0; count < k; ++count) {
            auto [currSum, currIndices] = minHeap.top();
            minHeap.pop();
            
            // If this is the k-th element extracted, return it
            if (count == k - 1) return currSum;
            
            // Generate new sums by moving to the next element in any row
            for (int i = 0; i < m; ++i) {
                vector<int> newIndices = currIndices;
                
                // Move to next element in row i if possible
                if (newIndices[i] + 1 < n) {
                    newIndices[i]++;
                    int newSum = currSum - mat[i][currIndices[i]] + mat[i][newIndices[i]];
                    
                    if (!seen.count(newIndices)) {
                        seen.insert(newIndices);
                        minHeap.push({newSum, newIndices});
                    }
                }
            }
        }
        
        return -1; // This should never be reached
    }
};

//other approach


class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int> temp=mat[0];
        for(int i=1;i<n;i++){
            vector<int> curr;
            for(int j=0;j<m;j++){
                for(int it=0;it<temp.size();it++){
                    curr.push_back(mat[i][j]+temp[it]);
                }
            }
            sort(curr.begin(),curr.end());
            temp.clear();
            for(int it=0;it<min((int)curr.size(),k);it++){
                temp.push_back(curr[it]);
            }
        }
        return temp[k-1];
    }
};


class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        
        // Start with first row values
        vector<int> temp = mat[0];

        for (int i = 1; i < n; i++) {
            priority_queue<int, vector<int>, greater<int>> minHeap;
            
            // Generate new sums using the next row
            for (int j = 0; j < m; j++) {
                for (int it : temp) {
                    minHeap.push(mat[i][j] + it);
                }
            }

            // Take only the smallest k elements
            temp.clear();
            for (int it = 0; it < k && !minHeap.empty(); it++) {
                temp.push_back(minHeap.top());
                minHeap.pop();
            }
        }

        return temp[k - 1];
    }
};
