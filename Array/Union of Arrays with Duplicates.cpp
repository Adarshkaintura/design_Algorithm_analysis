 int findUnion(vector<int>& a, vector<int>& b) {
      set<int> st;
      for(int i=0;i<a.size();i++){
          st.insert(a[i]);
      }
      for(int i=0;i<b.size();i++){
          st.insert(b[i]);
      }
    return st.size();
    }
