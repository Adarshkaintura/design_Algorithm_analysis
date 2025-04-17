int minJumps(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return 0;
    if (arr[0] == 0) return -1;

    int maxReach = arr[0];
    int steps = arr[0];
    int jumps = 1;

    for (int i = 1; i < n; i++) {
        if (i == n - 1) return jumps;

        maxReach = max(maxReach, i + arr[i]);
        steps--;

        if (steps == 0) {
            jumps++;
            if (i >= maxReach) return -1;
            steps = maxReach - i;
        }
    }

    return -1;
}

int minJumps(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return 0;
    if (arr[0] == 0) return -1;

    vector<int> temp(n, INT_MAX);
    temp[0] = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0 || temp[i] == INT_MAX) continue;

        for (int j = i + 1; j <= i + arr[i] && j < n; j++) {
            if (temp[j] > temp[i] + 1) {
                temp[j] = temp[i] + 1;
            }
        }
    }

    return temp[n - 1] == INT_MAX ? -1 : temp[n - 1];
}
