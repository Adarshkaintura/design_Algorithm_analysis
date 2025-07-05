class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
       int mon=money;
       int cnt=0;
       sort(prices.begin(),prices.end());
       for(int i=0;i<prices.size();i++){
        money-=prices[i];
        cnt++;
        if(money>=0 && cnt==2){
            return money;
        }
       } 
return mon;
    }
};
