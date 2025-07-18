                                                               //HashedIn
class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        
        map<int,multiset<char>> mp;
        int ans=0;
        for(int i=0;i<points.size();i++){
            mp[max(abs(points[i][0]),abs(points[i][1]))].insert(s[i]);
        }
        set<char> st;
        for(auto it:mp){
            set<char> tt;
            for(auto it1:it.second){
                if(tt.count(it1)>0 || st.count(it1)>0){
                    return ans;
                }
                else{
                    tt.insert(it1);
                }
            }
            for(auto it1:it.second){
                ans++;
                st.insert(it1);
            }
            
            
        }
        
        return ans;
    }
};
