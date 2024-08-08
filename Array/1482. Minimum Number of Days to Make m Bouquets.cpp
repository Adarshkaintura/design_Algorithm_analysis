class Solution {
public:
  bool solve(vector<int>& bloomDay,int md,int m,int k){
         int cnt = 0;
        int bouquets = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= md) {
                cnt++;
                if (cnt == k) {
                    bouquets++;
                    cnt = 0;
                }
            } else {
                cnt = 0;
            }
            if (bouquets >= m) {
                return true;
            }
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long ab=(long long)m*k;
        if(ab>bloomDay.size()){
            return -1;
        }
        int l=INT_MAX;
        int h=INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            l=min(bloomDay[i],l);
            h=max(bloomDay[i],h);
        }
        int ans=-1;
        while(l<=h){
            int md=(l+h)/2;
            if(solve(bloomDay,md,m,k)){
                ans=md;
                h=md-1;
            }else{
                l=md+1;
            }
        }
        return ans;
    }
};
