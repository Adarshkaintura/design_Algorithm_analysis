class Solution {
public:
    int minimumPushes(string word) {
        if(word.length()<=8){
            return word.length();
        }
        if(word.length()<=16){
            int a=word.length()-8;
            return 8+(a*2);
        }
        if(word.length()<=24){
           int a=word.length()-16;
           return 24+(a*3);
        }
        if(word.length()<=26){
            int a = word.length()-24;
            return 48+(a*4);
        }
        return 0;
    }
};
