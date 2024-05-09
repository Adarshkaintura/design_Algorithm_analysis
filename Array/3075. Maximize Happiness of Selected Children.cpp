class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size();
        sort(happiness.rbegin(),happiness.rend());
        long long ans=0;
        int j=0;
        for(int i=0;i<n;i++){
            if(k<=0){
                return ans;
            }
            int temp=happiness[i]-j;
            if(temp>=0){
               ans+=temp;
            }
             j++;
             k--;
        }
        return ans;
    }
};
