class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<vector<double>> pq;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                pq.push({(double)arr[i]/arr[j],(double)i,(double)j});
                if(pq.size()>k){
                    pq.pop();
                }
            }
        }
        auto it=pq.top();
        return {arr[it[1]],arr[it[2]]};
    }
};
