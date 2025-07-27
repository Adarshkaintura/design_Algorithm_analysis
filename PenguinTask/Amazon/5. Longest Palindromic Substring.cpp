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

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        
        int maxL  = 0;
        int index = 0;
        
        vector<vector<bool>> t(n, vector<bool>(n));
        
        maxL = 1; 
        for(int i = 0; i<n; i++) {
            t[i][i] = true;
            
        }
        
        for(int L = 2; L<=n; L++) {
            for(int i = 0; i<n-L+1; i++) {
                int j = i + L - 1;
                
                if(s[i] == s[j] && L == 2) {
                    t[i][j] = true;
                    maxL = 2;
                    index = i;
                } else if (s[i] == s[j] && t[i+1][j-1] == true) {
                    t[i][j] = true;
                    if(j-i+1 > maxL) {
                        maxL = j-i+1;
                        index = i;
                    }
                } else {
                    t[i][j] = false;
                }
                
            }    
        }
        
        
        return s.substr(index, maxL);
    }
};
