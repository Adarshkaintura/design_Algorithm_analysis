class Solution {
public:
    bool isPalindrome(string s){
        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        string ans = "";
        int maxlen = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string substring = s.substr(i, j - i + 1);
                if (isPalindrome(substring)) {
                    if (maxlen < (j - i + 1)) {
                        maxlen = j - i + 1;
                        ans = substring;
                    }
                }
            }
        }
        return ans;
    }
};

