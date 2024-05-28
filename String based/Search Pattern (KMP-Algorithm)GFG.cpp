   void LPS(string pat, vector<int>& lps) {
        int i = 1;
        lps[0] = 0;
        int length = 0;
        int m = pat.length();
        while (i < m) {
            if (pat[i] == pat[length]) {
                length += 1;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    vector<int> search(string pat, string txt) {
        vector<int> lps(pat.length());
        LPS(pat, lps);
        vector<int> result;
        int i = 0; // index for txt
        int j = 0; // index for pat
        int n = txt.length();
        int m = pat.length();
        while (i < n) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }
            if (j == m) {
                result.push_back(i - j+1);
                j = lps[j - 1];
            } else if (i < n && pat[j] != txt[i]) { // mismatch after j matches
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return result;
}
