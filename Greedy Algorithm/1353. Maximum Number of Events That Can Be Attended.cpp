class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());  // Sort by start time
        priority_queue<int, vector<int>, greater<int>> pq;  // Min-heap for end times
        int i = 0, n = events.size();
        int day = 0, ans = 0;

        while (i < n || !pq.empty()) {
            if (pq.empty()) {
                day = events[i][0];
            }

            // Push all events starting today
            while (i < n && events[i][0] <= day) {
                pq.push(events[i][1]);
                i++;
            }

            // Remove expired events
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }

            if (!pq.empty()) {
                pq.pop();  // Attend the event with the earliest end day
                ans++;
                day++;  // Move to the next day
            }
        }
        return ans;
    }
};
