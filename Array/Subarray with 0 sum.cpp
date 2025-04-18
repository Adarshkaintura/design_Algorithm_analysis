//brute
 bool subArrayExists(vector<int>& arr) {
       // I will use sliding window;
       int n=arr.size();
       
      for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==0){
                return true;
            }
        }   
      }
      return false;
    }

//opyimized 
 bool subArrayExists(vector<int>& arr) {
       // I will summ pproacg
       int n=arr.size();
       unordered_set<int> sumSet;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0 || sumSet.find(sum) != sumSet.end()) {
            return true;
        }

        sumSet.insert(sum);
    }

    return false;
    }
