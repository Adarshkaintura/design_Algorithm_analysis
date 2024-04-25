 long long minCost(long long arr[], long long n) {
    long long ans = 0;
    priority_queue<long long, vector<long long>, greater<long long>> minh; // Use a min-heap

    // Push elements into the min-heap
    for (int i = 0; i < n; i++) {
        minh.push(arr[i]);
    }

    // Merge elements until there is only one element left in the heap
    while (minh.size() > 1) {
        long long a = minh.top(); // Use long long instead of int
        minh.pop();
        long long b = minh.top(); // Use long long instead of int
        minh.pop();
        ans+=(a+b);
        minh.push(a + b);
    }

    // The remaining element in the heap is the total minimum cost

    return ans;
}
