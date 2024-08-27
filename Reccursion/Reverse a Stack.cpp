   void helper(stack<int> &st,int ele){
       if(st.empty()){
           st.push(ele);
           return;
       }
      int top=st.top();
      st.pop();
      helper(st,ele);
      st.push(top);
      return;
   }
    void Reverse(stack<int> &st){
        if(st.empty()){
            return;
        }
      int top=st.top();
      st.pop();
      Reverse(st);
      helper(st,top);
      return;
    }
