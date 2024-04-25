 long long findMinDiff(vector<long long> a, long long n, long long m){
    long long mini=INT_MAX;
    sort(a.begin(),a.end());
    int i=0;
    int j=m-1;
    while(j<n){
        mini=min(mini,a[j]-a[i]);
        i++;
        j++;
    }
    return mini;
    } 
