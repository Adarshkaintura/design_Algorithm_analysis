class Solution
{
    public:
    void helper(Node* root,vector<int>& ans){
        if(root==NULL){
            ans.push_back(-1);
            return;
        }
        ans.push_back(root->data);
          helper(root->left,ans);
        helper(root->right,ans);
    }
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        vector<int> ans;
        helper(root,ans);
        return ans;
    }
    
    //Function to deserialize a list and construct the tree.
       Node* deSerializeHelper(vector<int>& serialized, int& index) {
        if (index >= serialized.size() || serialized[index] == -1) {
            index++; // Move index to next element
            return nullptr;
        }
        
        Node* root = new Node(serialized[index++]);
        root->left = deSerializeHelper(serialized, index);
        root->right = deSerializeHelper(serialized, index);
              
        return root;
    }
    
    // Function to deserialize an array and construct the tree.
    Node * deSerialize(vector<int> &A) {
        int index = 0;
        return deSerializeHelper(A, index);
    }

};
