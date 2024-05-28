class Solution {
public:
    int strStr(string haystack, string needle) {
        // Base cases
        if (needle.empty()) return 0; // If needle is empty, return 0
        if (haystack.empty() || haystack.length() < needle.length()) return -1;

        const int base = 256; // Base for the hash function (number of characters in the input alphabet)
        const int prime = 101; // A prime number used for modulo operation to reduce hash values
        int m = needle.length();
        int n = haystack.length();

        int needleHash = 0; // Hash value for needle
        int haystackHash = 0; // Hash value for current window of haystack
        int h = 1; // The value of base^(m-1) % prime

        // Precompute h = pow(base, m-1) % prime
        for (int i = 0; i < m - 1; i++) {
            h = (h * base) % prime;
        }

        // Compute the hash values for needle and the first window of haystack
        for (int i = 0; i < m; i++) {
            needleHash = (base * needleHash + needle[i]) % prime;
            haystackHash = (base * haystackHash + haystack[i]) % prime;
        }

        // Slide the pattern over the text one by one
        for (int i = 0; i <= n - m; i++) {
            // Check the hash values of current window of text and pattern
            if (needleHash == haystackHash) {
                // If the hash values match, check for characters one by one
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (haystack[i + j] != needle[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) return i; // If all characters match, return the start index
            }

            // Calculate hash value for next window of text
            if (i < n - m) {
                haystackHash = (base * (haystackHash - haystack[i] * h) + haystack[i + m]) % prime;
                // We might get negative value of haystackHash, convert it to positive
                if (haystackHash < 0) {
                    haystackHash += prime;
                }
            }
        }

        return -1; // If no match found
    }
};
