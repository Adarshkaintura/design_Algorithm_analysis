class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans=0;
         sort(g.begin(),g.end());
         sort(s.begin(),s.end());
         
        for(int i=0;i<g.size();i++){
            for(int j=0;j<s.size();j++){
                if(g[i]<=s[j]){
                    ans++;
                    s[j]=0;
                    break;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int child = 0, cookie = 0;

        while (child < g.size() && cookie < s.size()) {
            if (g[child] <= s[cookie]) {
                // This cookie satisfies this child
                child++;
            }
            // Try next cookie regardless of whether we satisfied a child
            cookie++;
        }

        return child;
    }
};
