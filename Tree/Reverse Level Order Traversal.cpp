vector<int> reverseLevelOrder(Node *root)
{
    queue<Node*> q;
    vector<int> ans;
    q.push(root);
    while(!q.empty()){
        int len=q.size();
       vector<int> tm;
        for(int i=0;i<len;i++){
            Node* temp=q.front();
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
             q.push(temp->right);   
            }
            q.pop();
             tm.push_back(temp->data);
        }
        reverse(tm.begin(),tm.end());
        ans.insert(ans.end(), tm.begin(), tm.end());
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
