class Solution {
public:
    static int equalSubstring(string& s, string& t, int maxCost) {
        const int n=s.size();
        int i=0;
        int j=0;
        int len=0;
      
        int cost=0;
        while(i<s.size() && j<s.size() && i<=j){
               cost += abs(s[j]-t[j]);
              while(cost>maxCost){
                cost -= abs(s[i]-t[i]);
                i++;
              }
             len=max(len,j-i+1);
              j++;
              
        }
        return len;
    }
};


