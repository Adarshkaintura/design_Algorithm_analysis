class Solution {
public:
    int possibleStringCount(string word) {
        int ans=1;
        int freq=0;
        for(int i=1;i<word.length();i++){
            if(word[i-1]==word[i]){
                freq+=1;
            }else{
                ans+=freq;
                freq=0;
            }
        }
        if(freq!=0){
            ans+=freq;
        }
        return ans;
    }
};
