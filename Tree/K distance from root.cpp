class Solution
{
    public:
    // function should print the nodes at k distance from root
    void helper(struct Node *root,int a,int k,vector<int>& ans){
        if(root==NULL || a>k){
            return;
        }
           if(a==k && root!=NULL){
          ans.push_back(root->data); 
          return;
        }
        helper(root->left,a+1,k,ans);
     
        helper(root->right,a+1,k,ans);
    }
    vector<int> Kdistance(struct Node *root, int k)
    {
      vector<int> ans;
      helper(root,0,k,ans);
      return ans;
    }
};
