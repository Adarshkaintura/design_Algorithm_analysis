class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
      unordered_map<int,int> mp;
      vector<int> tempi=score;
      sort(tempi.rbegin(),tempi.rend());
      for(int i=0;i<score.size();i++){
            mp[tempi[i]]=i+1;
      }
         int first = INT_MIN, second = INT_MIN, third = INT_MIN;
    for (int num : score) {
        if (num > first) {
            third = second;
            second = first;
            first = num;
        } else if (num > second) {
            third = second;
            second = num;
        } else if (num > third) {
            third = num;
        }
    }
        vector<string> ans;
        for(int i=0;i<score.size();i++){
            if(score[i]==first){
                ans.push_back("Gold Medal");
            }
            else if(score[i]==second){
                ans.push_back("Silver Medal");
            }else if(score[i]==third){
                ans.push_back("Bronze Medal");
            }else{
                ans.push_back(to_string(mp[score[i]]));
            }
        }
return ans;
    }
};
