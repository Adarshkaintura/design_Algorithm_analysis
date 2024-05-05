class Solution{
  public:
 map<int,int> mp;
 void preorder(Node* node,int level){
     if(node!=NULL){
         mp[level]+=node->data;
         preorder(node->left,level-1);
         preorder(node->right,level+1);
         return;
     }
 }
  
    vector <int> verticalSum(Node *root) {
       vector<int> ans;
preorder(root,0);
for(auto it:mp){
    ans.push_back(it.second);
}
       return ans;
    }
};
