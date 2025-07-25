  vector<long long> jugglerSequence(long long n) {
       vector<long long> ans={n};
       long long prev=n;
       while(prev!=1){
           if(prev%2!=1){
               ans.push_back(sqrt(prev));
           }else{
               ans.push_back(sqrt(pow(prev,3)));
           }
           prev=ans.back();
       }
       return ans;
    }
