//brute 
class Solution {
public:
    long long ans = INT_MIN;
    
    void helper(vector<int>& nums1, vector<int>& nums2, int k, int i, int mini, long long sum) {
        if (i == nums1.size()) {
           if (k == 0) {
                ans = max(ans, sum * mini);
            }
            return;
        }
            if (k == 0) {
            ans = max(ans, sum * mini);
            return;
        }
        
        helper(nums1, nums2, k, i + 1, mini, sum);
        
        int updated_mini = min(mini, nums2[i]);
        sum += nums1[i];
        k -= 1;
        
        helper(nums1, nums2, k, i + 1, updated_mini, sum);
    }
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int mini = INT_MAX;
        long long sum = 0;
        helper(nums1, nums2, k, 0, mini, sum);
        return ans;
        
    }
};
//optimized
class Solution {
public:
   
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
       vector<pair<int,int>> newarr;
       for(int i=0;i<nums1.size();i++){
        newarr.push_back({nums2[i],nums1[i]});
       }
    sort(newarr.rbegin(),newarr.rend());
    long long ksum=0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<k;i++){
          ksum+=newarr[i].second;
             pq.push(newarr[i].second);
    }
    long long result=ksum*newarr[k-1].first;
    for(int i=k;i<nums1.size();i++){
        ksum+=newarr[i].second;
        ksum-=pq.top();
        pq.pop();
        pq.push(newarr[i].second);
        result=max(result,ksum*newarr[i].first);
    }
return result;
    }
};
