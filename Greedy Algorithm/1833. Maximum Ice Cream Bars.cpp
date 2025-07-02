class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs), end(costs));
        
        int count = 0;
        
        for(int &cost : costs) {
            if(cost > coins)
                return count;
            else {
                count++;
                coins -= cost;
            }
        }
        
        return count;
    }
};
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int cnt=0;
        for(int i=0;i<costs.size();i++){
            if(coins>=costs[i]){
                coins-=costs[i];
                cnt++;
            }else{
                break;
            }
        }
        return cnt;
    }
};
