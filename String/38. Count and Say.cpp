class Solution {
public:
    vector<pair<int, int>> generatePair(string s) {
        vector<pair<int, int>> ans;
        int n = s.length();
        int count = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                ans.push_back({count, s[i - 1]});
                count = 1;
            }
        }

        ans.push_back({count, s[n - 1]});
        return ans;
    }

    string generateString(vector<pair<int, int>> arr) {
        string s = "";
        for (auto p : arr) {
            s += to_string(p.first);
            s += (char)p.second;
        }
        return s;
    }

    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }

        string prev = countAndSay(n - 1);
        vector<pair<int, int>> pairs = generatePair(prev);
        return generateString(pairs);
    }
};
