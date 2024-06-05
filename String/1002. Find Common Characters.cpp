class Solution {
public:
   void fillCount(vector<int>& arr,string s){
    for(auto ch:s){
        arr[ch-'a']++;
    }
   }
    vector<string> commonChars(vector<string>& words) {
        vector<int> arr(26,0);
        fillCount(arr,words[0]);
        for(auto word:words){
            vector<int> temp(26,0);
            fillCount(temp,word);
            for(int i=0;i<26;i++){
                if(arr[i]!=temp[i]){
                    arr[i]=min(arr[i],temp[i]);
                }
            }
        }
        vector<string> ans;
        for(int i=0;i<26;i++){
           int c=arr[i];
           while(c--){
            ans.push_back(string(1,i+'a'));
           }
        }
        return ans;
    }
};
