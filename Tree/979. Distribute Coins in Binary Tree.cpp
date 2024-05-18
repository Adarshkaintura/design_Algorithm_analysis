/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   
     int helper(TreeNode* root,int& moves){
       if(root==nullptr){
            return 0;
        }
        int l=helper(root->left,moves);
        int r=helper(root->right,moves);
        moves+=abs(l)+abs(r);
        return (l+r+root->val)-1;
     }
     
    int distributeCoins(TreeNode* root) {
        int moves=0;
       helper(root,moves);
       return moves;
    }
};
