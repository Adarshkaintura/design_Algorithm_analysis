class Solution {
  public:
  static bool cmp(pair<double,Item> a,pair<double,Item>b){
      return a.first>b.first;
  }
    // Function to get the maximum total value in the knapsack.
   double fractionalKnapsack(int w, Item arr[], int n) {
    double ans = 0;
    vector<pair<double,Item>> v;
    for (int i = 0; i < n; i++) {
        double valbywt = 1.0 * (arr[i].value) / arr[i].weight; // Cast to double
        v.push_back({valbywt, arr[i]});
    }
    
    sort(v.begin(), v.end(),cmp);
    for (int i = 0; i < n; i++) {
       if(w<v[i].second.weight){
           ans+=v[i].first*w;
           w=0;
       }else{
           w=w-v[i].second.weight;
           ans+=v[i].second.value;
       }
    }
    return ans;
}
