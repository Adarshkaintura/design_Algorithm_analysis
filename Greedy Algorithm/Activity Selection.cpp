  int activitySelection(vector<int> start, vector<int> end, int n) {
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++) {
        v.push_back({end[i], start[i]});
    }
    sort(v.begin(), v.end());
    int count = 0; // Count the first activity
    int prevend = 0;
    for(int i = 0; i < n; i++) {
        if(prevend <v[i].second) { // Compare with start time
            count++;
            prevend = v[i].first;
        }
    }
    return count;
}
