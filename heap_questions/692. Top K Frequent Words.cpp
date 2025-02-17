class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        
        // Step 1: Count frequency of each word
        for (const string& word : words) {
            freq[word]++;
        }

        // Step 2: Use min-heap to store top K frequent words
        auto cmp = [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first == b.first) return a.second > b.second; // Lexicographic order if frequencies are same
            return a.first < b.first;  // Higher frequency should come first
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);

        for (const auto& entry : freq) {
            pq.push({entry.second, entry.first});
        }

        // Step 3: Extract the top K words
        vector<string> result;
        while (k-- && !pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
