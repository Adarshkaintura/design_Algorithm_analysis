    int depthOfOddLeaf(Node *root) {
    if (!root) return 0; // Edge case: empty tree

    queue<pair<Node*, int>> q;
    q.push({root, 1});
    int ans = 0;

    while (!q.empty()) {
        auto it = q.front();
        q.pop();

        Node* nd = it.first;
        int level = it.second;

        // Only update answer if it's a leaf at an odd level
        if (!nd->left && !nd->right && level % 2 == 1) {
            ans = max(ans, level);
        }

        if (nd->left) q.push({nd->left, level + 1});
        if (nd->right) q.push({nd->right, level + 1});
    }

    return ans; // If no odd-level leaf exists, returns 0
}
