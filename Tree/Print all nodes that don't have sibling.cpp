void helper(Node* root,vector<int>& ans){
    if(root==NULL){
        return;
    }
     helper(root->left,ans);
    if(root->left!=NULL && root->right==NULL){
        ans.push_back(root->left->data);
    }else if(root->left==NULL && root->right!=NULL){
        ans.push_back(root->right->data);
    }
   
    helper(root->right,ans);
}
vector<int> noSibling(Node* node)
{
   vector<int> ans;
   helper(node,ans);
   if(ans.empty()){
       ans.push_back(-1);
       return ans;
   }
   sort(ans.begin(),ans.end());
   return ans;
}
