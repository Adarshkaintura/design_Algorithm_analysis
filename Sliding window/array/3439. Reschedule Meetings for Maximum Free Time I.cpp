class Solution {
public:
    // Kadane variant: Max sum of any subarray of size exactly k
    int kadaneAlgo(vector<int>& arr, int k) {
        if (arr.size() < k){
            int sum=0;
            for(int i=0;i<arr.size();i++){
                sum+=arr[i];
            }
            return sum;
        }
        int windowSum = 0, maxSum = 0;

        // Sum of first k elements
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }

        maxSum = windowSum;

        // Slide the window
        for (int i = k; i < arr.size(); i++) {
            windowSum += arr[i] - arr[i - k];
            maxSum = max(maxSum, windowSum);
        }

        return maxSum;
    }

    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        
        vector<int> kadane;
        kadane.push_back(startTime[0]);
   for(int i=1;i<startTime.size();i++){
      kadane.push_back(startTime[i]-endTime[i-1]);
   }
kadane.push_back(eventTime-endTime[startTime.size()-1]);
        int ans = kadaneAlgo(kadane, k + 1);
        return ans;
    }
};
