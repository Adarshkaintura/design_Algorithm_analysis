//brute;
int pairWithMaxSum(vector<int> &arr) {
       int maxScore = INT_MIN;
        int n = arr.size();

        for (int i = 0; i < n; ++i) {
            int min1 = INT_MAX, min2 = INT_MAX;
            for (int j = i; j < n; ++j) {
                if (arr[j] < min1) {
                    min2 = min1;
                    min1 = arr[j];
                } else if (arr[j] < min2) {
                    min2 = arr[j];
                }
                if (min2 != INT_MAX) {
                    maxScore = std::max(maxScore, min1 + min2);
                }
            }
        }
        
        return maxScore;
    }
//optimized
 int pairWithMaxSum(vector<int> &arr) {
        int n = arr.size();
        int ans = 0;
        for(int i=0;i<n-1;i++){
            ans = max(arr[i]+arr[i+1], ans);
        }
        return ans;
    }
