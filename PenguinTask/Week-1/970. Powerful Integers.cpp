class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> st;
        int n1=0,n2=0;

        while(pow(x,n1)<=bound && x!=1){
            n1++;
        }
        while(pow(y,n2)<=bound && y!=1){
            n2++;
        }
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                int ans=pow(x,i)+pow(y,j);
                if(ans<=bound){
                    st.insert(ans);
                }
            }
        }
        vector<int> ansi(st.begin(),st.end());
        return ansi;
    }
};
