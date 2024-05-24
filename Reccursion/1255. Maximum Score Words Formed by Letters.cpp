class Solution {
public:
int maxScore;
   void solve(int i,vector<string>& words,vector<int>& freq,vector<int>& score,int currscore){
     maxScore=max(maxScore,currscore);
     if(i==words.size()){
          return;
     }
     vector<int> temp=freq;
     int j=0;
     int n=words[i].size();
     int tempScore=0;
     while(j<n){
          char ch=words[i][j];
          freq[ch-'a']--;
         tempScore += score[ch-'a'];
          if(freq[ch-'a']<0){
            break;
          }
          j++;
     }
   if(j==words[i].size()){
      solve(i+1,words,freq,score,tempScore+currscore);
   }
      return solve(i+1,words,temp,score,currscore);
   }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26,0);
        for(int i=0;i<letters.size();i++){
            freq[letters[i]-'a']++;
        }
        maxScore=INT_MIN;
        int n=words.size();
        solve(0,words,freq,score,0);
        return maxScore;
    }
};
