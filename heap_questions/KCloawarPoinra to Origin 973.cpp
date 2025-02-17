class Solution {
public:
    int findDist(int a, int b) {
        return a * a + b * b; // Squared distance to avoid sqrt()
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max heap to keep track of the k closest points
        priority_queue<pair<int, int>> pq; 
        
        for (int i = 0; i < points.size(); i++) {
            int dist = findDist(points[i][0], points[i][1]);
            pq.push({dist, i}); // Store {distance, index}

            if (pq.size() > k) {
                pq.pop(); // Remove the farthest point
            }
        }

        vector<vector<int>> result;
        while (!pq.empty()) {
            result.push_back(points[pq.top().second]); // Extract points using index
            pq.pop();
        }

        return result;
    }
};
