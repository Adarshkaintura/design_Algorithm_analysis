// real hard one question
   int solve(vector<int> &arr, double dist) {
    int cnt = 0;
    for (int i = 1; i < arr.size(); i++) {
        int nib = (int)((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == nib * dist) {
            nib--;  // Adjust if it's an exact division
        }
        cnt += nib;
    }
    return cnt;
}

double findSmallestMaxDist(vector<int> &stations, int k) {
    double l = 0;
    double h = 0;
    for (int i = 1; i < stations.size(); i++) {
        h = max(h, (double)(stations[i] - stations[i - 1]));
    }

    while ((h - l) > 1e-4) {  // Fixed condition
        double mid = (h + l) / 2.0;
        int cnt = solve(stations, mid);
        if (cnt > k) {
            l = mid;
        } else {
            h = mid;
        }
    }
    return h;
}
