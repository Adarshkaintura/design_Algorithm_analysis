int ub(vector<int>& row, int C, int x) {
    int low = 0, high = C - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (row[mid] <= x) {
            low = mid + 1; // Move to the right half if mid element is <= x
        } else {
            high = mid - 1; // Move to the left half otherwise
        }
    }
    return low; // `low` is the number of elements <= x
}

int bb(vector<vector<int>>& matrix, int R, int C, int mid) {
    int cnt = 0;
    for (int i = 0; i < R; i++) {
        cnt += ub(matrix[i], C, mid);
    }
    return cnt;
}

int median(vector<vector<int>>& matrix, int R, int C) {
    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < R; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][C-1]);
    }

    int desired = (R * C + 1) / 2; // The median position in a 1-based index

    while (low < high) {
        int mid = low + (high - low) / 2;
        int cntLessEqual = bb(matrix, R, C, mid);
        if (cntLessEqual < desired) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low; // `low` now holds the median
}
