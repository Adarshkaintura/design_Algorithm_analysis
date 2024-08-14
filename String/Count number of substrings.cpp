long long int countOfsub(string s,int k){
         int f=0;
         long long int ans=0;
         vector<int> freq(26,0);
         int i=0,j=0;
         int n=s.length();
         for(i=0;i<n;i++){
             while(j<n && f<k){
                  freq[s[j]-'a']++;
                 if(freq[s[j]-'a']==1){
                     f++;  
                 }
                
                j++;
             }
             if(f>=k){
                 ans=ans+n-j+1;
             }
             freq[s[i]-'a']--;
             if(freq[s[i]-'a']==0){
                 f--;
             }
         }
         return ans;
     }
  public:
    long long int substrCount (string s, int k) {
   long long int ans=0;
   ans=countOfsub(s,k)-countOfsub(s,k+1);
   return ans;
     
 }
    
