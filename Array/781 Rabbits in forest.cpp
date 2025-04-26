//brute solution
class Solution {
public:
    int numRabbits(vector<int>& answers) {
       sort(answers.begin(),answers.end());
       int rabbits=answers[0]+1;
       int cnt=answers[0]+1;
       for(int i=1;i<answers.size();i++){
         if(answers[i]!=answers[i-1]){
            cnt=answers[i]+1;
            rabbits+=answers[i]+1;
         }else if(answers[i]==answers[i-1]){
            cnt--;
            if(cnt==0){
                rabbits+=answers[i]+1;
                cnt=answers[i]+1;
            }
             
         }
       }
       return rabbits;
    }
};
