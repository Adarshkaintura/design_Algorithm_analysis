 int countNumberswith4(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
        string s=to_string(i);
        for(auto it:s){
            if(it=='4'){
                ans++;
                break;
            }
        }
        }
        return ans;
    }
