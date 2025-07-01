class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> flower;
        for(int i=0;i<plantTime.size();i++){
            flower.push_back({growTime[i],plantTime[i]});
        }
        int maxDays=INT_MIN;
        int prevDay=0;
        auto lambda=[](pair<int,int>& p1,pair<int,int>& p2){
            return p1.first>p2.first;
        };
        sort(flower.begin(),flower.end(),lambda);
        for(int i=0;i<flower.size();i++){
            prevDay+=flower[i].second;
            maxDays=max(prevDay+flower[i].first,maxDays);
        }
        return maxDays;
    }
};
