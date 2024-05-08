class Solution {
  public:
      
     void helper(Node* root,vector<vector<int>>& ans,vector<int> temp){
         if(root==NULL){
             return;
         }
         if(root->left==NULL && root->right==NULL){
             temp.push_back(root->data);
             ans.push_back(temp);
         }
         temp.push_back(root->data);
         helper(root->left,ans,temp);
         
         helper(root->right,ans,temp);
     }
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        vector<int> temp;
        helper(root,ans,temp);
        return ans;
    }
};
