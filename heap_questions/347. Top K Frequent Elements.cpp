class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // Store frequency of each number
        for (int num : nums) {
            mp[num]++;
        }

        // Min heap (stores k elements, least frequent element at top)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for (auto it : mp) {
            pq.push({it.second, it.first}); // {frequency, number}
            if (pq.size() > k) {
                pq.pop(); // Remove least frequent
            }
        }

        // Extract k most frequent elements from heap
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};
