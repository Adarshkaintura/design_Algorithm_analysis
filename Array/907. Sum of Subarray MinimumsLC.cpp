class Solution {
public:
vector<int> getNSL(vector<int>& arr,int n){
    vector<int> result(n);
    stack<int> st;
    for(int i=0;i<n;i++){
      if(st.empty()){
        result[i]=-1;
      }else{
        while(!st.empty() && arr[st.top()]>arr[i]){
            st.pop();
        }
        result[i]=st.empty()?-1:st.top();
      }
      st.push(i);
    }
    return result;
}
vector<int> getNSR(vector<int>& arr,int n){
    vector<int> result(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
      if(st.empty()){
        result[i]=n;
      }else{
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        result[i]=st.empty()?n:st.top();
      }
      st.push(i);
    }
    return result;
}
      int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9+7;
        int n=arr.size();
        vector<int> NSL(n);
        vector<int> NSR(n);
        NSL=getNSL(arr,n);
        NSR=getNSR(arr,n);

        long long sum=0;
        for(int i=0;i<n;i++){
            long long d1=i-NSL[i];
            long long d2=NSR[i]-i;

            long long product=d1*d2*arr[i];
            sum=(sum+product)%mod;

        }
        return sum;
    }
};
