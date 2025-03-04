class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> time(n);

        // Compute the time taken for each monster to reach the city
        for(int i = 0; i < n; i++) {
            time[i] = (double) dist[i] / speed[i]; // Ensure floating-point division
        }

        // Sort the arrival times in ascending order
        sort(time.begin(), time.end());

        // Eliminate monsters one by one
        for(int i = 1; i < n; i++) {
            if(time[i]-i<=0 ) { // If a monster reaches before it can be eliminated
                return i;
            }
        }

        return n; // All monsters eliminated
    }
};
