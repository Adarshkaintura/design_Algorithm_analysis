class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        unordered_map<char,int> mp;
        int tt=0;
        for(int i=1;i<neededTime.size();i++){
            if(colors[i-1]==colors[i]){
                if(neededTime[i-1]==0){
                   if(mp[colors[i]]<neededTime[i]){
                     tt+=mp[colors[i]];
                     mp[colors[i]]=neededTime[i];
                   }else{
                    tt+=neededTime[i];
                    neededTime[i]=0;
                   }
                }else{
                    if(neededTime[i-1]<neededTime[i]){
                        mp[colors[i]]=neededTime[i];
                        tt+=neededTime[i-1];
                        neededTime[i-1]=0;
                    }else{
                        mp[colors[i]]=neededTime[i-1];
                        tt+=neededTime[i];
                        neededTime[i]=0;
                    }
                }
            }
        }
        return tt;
    }
};
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        
        int time    = 0;
        int prevMax = 0;
        
        for(int i = 0; i<n; i++) {
            
            if(i > 0 && colors[i] != colors[i-1]) {
                prevMax = 0;
            }
            
            
            
            int curr = neededTime[i];
            
            time += min(prevMax, curr); //greedily
            
            prevMax = max(prevMax, curr);
            
        }
        
        return time;
    }
};



