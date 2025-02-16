  void leftside(Node *root, vector<int> &ans) {
    if (!root || (!root->left && !root->right)) return; // Skip leaf nodes

    ans.push_back(root->data);
    if (root->left) leftside(root->left, ans);
    else leftside(root->right, ans);
}

void rightside(Node *root, vector<int> &ans) {
    if (!root || (!root->left && !root->right)) return; // Skip leaf nodes

    if (root->right) rightside(root->right, ans);
    else rightside(root->left, ans);
    ans.push_back(root->data); // Add after recursion (bottom-up)
}

void rootside(Node *root, vector<int> &ans) {
    if (!root) return;
    
    if (!root->left && !root->right) ans.push_back(root->data); // Add only leaves
    if (root->left) rootside(root->left, ans);
    if (root->right) rootside(root->right, ans);
}

vector<int> boundaryTraversal(Node *root) {
    if (!root) return {};

    vector<int> ans;
    ans.push_back(root->data); // Root is always included

    leftside(root->left, ans);
    rootside(root->left, ans);
    rootside(root->right, ans);
    rightside(root->right, ans);

    return ans;
}
