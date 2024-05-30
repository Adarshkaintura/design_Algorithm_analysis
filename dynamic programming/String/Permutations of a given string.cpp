private:
    void solve(string& S,int index,vector<string>& ans){
        if(index==S.length()){
            ans.push_back(S);
            return;
        }
        for(int i=index;i<S.length();i++){
            swap(S[i],S[index]);
            solve(S,index+1,ans);
            swap(S[i],S[index]);
        }
    }
	public:
		vector<string>find_permutation(string S)
		{
		   vector<string> ans;
		   solve(S,0,ans);
		   
		   unordered_set<string> st(ans.begin(),ans.end());
		   sort(ans.begin(),ans.end());
		   ans.assign(st.begin(),st.end());
		   return ans;
		}
