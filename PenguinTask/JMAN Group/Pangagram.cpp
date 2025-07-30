bool isPangramBrute(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);  // Convert to lowercase
    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (s.find(ch) == string::npos) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<string> sentences = {
        "The quick brown fox jumps over the lazy dog",
        "Hello World",
        "Pack my box with five dozen liquor jugs"
    };

    for (const string& s : sentences) {
        if (isPangramBrute(s))
            cout << "\"" << s << "\" is a Pangram.\n";
        else
            cout << "\"" << s << "\" is NOT a Pangram.\n";
    }

    return 0;
}
//optimized
bool isPangramOptimized(const string& s) {
    bool seen[26] = {false};
    int count = 0;

    for (char c : s) {
        if (isalpha(c)) {
            c = tolower(c);
            int idx = c - 'a';
            if (!seen[idx]) {
                seen[idx] = true;
                count++;
            }
        }
    }

    return count == 26;
}

int main() {
    vector<string> sentences = {
        "The quick brown fox jumps over the lazy dog",
        "Hello World",
        "Pack my box with five dozen liquor jugs"
    };

    for (const string& s : sentences) {
        if (isPangramOptimized(s))
            cout << "\"" << s << "\" is a Pangram.\n";
        else
            cout << "\"" << s << "\" is NOT a Pangram.\n";
    }

    return 0;
}
