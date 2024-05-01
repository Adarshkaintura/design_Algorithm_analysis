class Solution {
public:
    void reversestring(string& word,int i,int j){
         while(i<j){
            char temp=word[i];
            word[i]=word[j];
            word[j]=temp;
            i++;
            j--;
         }

    }
    string reversePrefix(string word, char ch) {
        for(int i=0;i<word.length();i++){
            if(word[i]==ch){
                reversestring(word,0,i);
                return word;
            }
        }
        return word;
    }
};
