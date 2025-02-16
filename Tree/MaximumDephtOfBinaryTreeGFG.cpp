  int maxDepth(Node *root) {
        if(root==NULL){
            return 0;
        }
        queue<pair<Node*,int>> q;
        q.push({root,1});
        int ans=0;
        while(!q.empty()){
            auto it=q.front();
            Node* nd=it.first;
            int level=it.second;
            if(!nd->left && !nd->right){
                ans=max(ans,level);
            }
            if(nd->left){
                q.push({nd->left,level+1});
            }
            if(nd->right){
                q.push({nd->right,level+1});
            }
            q.pop();
        }
        return ans;
        
        
    }
