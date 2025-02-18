//tle heere
class Solution {
public:
   

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
         // Custom comparator for the priority queue
    auto cmp = [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
        if (a.first == b.first) {
            // If sums are the same, compare lexicographically by the first element of the pairs
            return a.second.first < b.second.first;
        }
        return a.first < b.first;  // Otherwise, compare by sum
    };
        // Priority queue using custom comparator
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(cmp)> pq(cmp);

        // Insert the sum of pairs along with the actual pairs
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                pq.push({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
                
                // If the size of the priority queue exceeds k, pop the largest element
                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }

        // Collect the ka smallest pairs from the priority queue
        while (!pq.empty()) {
            int a = pq.top().second.first;
            int b = pq.top().second.second;
            ans.push_back({a, b});
            pq.pop();
        }

        // The heap gives the largest pair first, so we reverse the answer vector
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
// running
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        
        // Priority queue (min-heap) to store pairs along with their sum
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        // Insert the first pair from nums1 and nums2
        for (int i = 0; i < min(k, (int)nums1.size()); ++i) {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }

        // Extract the smallest pairs and expand the heap
        while (k-- && !pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            int i = top.second.first;  // index in nums1
            int j = top.second.second; // index in nums2
            ans.push_back({nums1[i], nums2[j]});
            
            // If there's a next element in nums2 for the same element in nums1, push it to the heap
            if (j + 1 < nums2.size()) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
        }
        
        return ans;
    }
};
