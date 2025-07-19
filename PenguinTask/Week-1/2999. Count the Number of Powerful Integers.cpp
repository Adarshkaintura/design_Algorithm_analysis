//tle came
class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        long long ans=0;
        for(long long num=start;num<=finish;num++){
           string str=to_string(num);
          if (str.length() >= s.length()) {
    string s1 = str.substr(str.length() - s.length(), s.length());
    if (s1 == s) {
        bool flag = true;
        for (int i = 0; i < str.length(); i++) {
            int a = str[i] - '0';
            if (a > limit) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans++;
        }
    }
}

        }
        return ans;
    }
};

class Solution {
public:
    long long solve(string str, int limit, string s) {
        if(str.length() < s.length()) return 0;

        int n = str.length() - s.length();
        long long count = 0;

        for(int i = 0; i < n; i++) {
            int a = str[i] - '0';
            if(a <= limit) {
                count += a * pow(limit + 1, n - i - 1);
            } else {
                count += pow(limit + 1, n - i);
                return count;
            }
        }

        string trailString = str.substr(str.length() - s.length());
        if(trailString >= s) count += 1;

        return count;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string s1 = to_string(start - 1);
        string s2 = to_string(finish);
        return solve(s2, limit, s) - solve(s1, limit, s);
    }
};
