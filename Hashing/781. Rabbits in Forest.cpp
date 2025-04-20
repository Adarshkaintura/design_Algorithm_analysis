class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        for(int i=0;i<answers.size();i++){
            mp[answers[i]]++;
        }
        int minRabits=0;
        int x,freq,group,groupsize;
        for(auto it:mp){
            x=it.first;
            freq=it.second;
            groupsize=x+1;
            group = ceil((double)freq / groupsize);

            minRabits+=group*groupsize;

        }
        return minRabits;
    }
};
