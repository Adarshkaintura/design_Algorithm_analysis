class Solution {
public:
    int minDeletion(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Count how many distinct characters exist
        vector<int> used;
        for (int f : freq) {
            if (f > 0) {
                used.push_back(f);
            }
        }

        // If distinct characters <= k, no deletion needed
        if (used.size() <= k) return 0;

        // Sort frequencies in ascending order
        sort(used.begin(), used.end());

        // Remove smallest frequency characters until we have only k
        int deletions = 0;
        int remove_count = used.size() - k;
        for (int i = 0; i < remove_count; i++) {
            deletions += used[i];
        }

        return deletions;
    }
};
