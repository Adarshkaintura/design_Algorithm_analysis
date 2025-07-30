//tle code
class Solution {
public:
bool isAnagram(string s1, string s2) {
    if (s1.size() != s2.size()) return false;

    unordered_map<char, int> mp;
    for (char ch : s1) {
        mp[ch]++;
    }

    for (char ch : s2) {
        if (mp.find(ch) == mp.end() || mp[ch] == 0) {
            return false;
        }
        mp[ch]--;
    }

    return true;
}

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<bool> visited(strs.size(),false);
        for(int i=0;i<strs.size();i++){
            if(visited[i]) continue;
          vector<string> temp;
          string s=strs[i];
          temp.push_back(s);
          visited[i]=true;
          for(int j=i+1;j<strs.size();j++){
             if(isAnagram(s,strs[j]) && !visited[j]){
                temp.push_back(strs[j]);
                visited[j]=true;
             }
          }
          ans.push_back(temp);

        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for (const string& s : strs) {
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end());
            mp[sorted_s].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto& entry : mp) {
            ans.push_back(entry.second);
        }
        return ans;
    }
};
