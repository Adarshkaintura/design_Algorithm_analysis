   vector<int> bottomView(Node *root) {
    if (!root) return {};  // Handle edge case where root is NULL

    unordered_map<int, int> mp;  // Stores horizontal distance -> bottommost node value
    queue<pair<Node*, int>> q;  // Queue to store (node, horizontal distance)
    q.push({root, 0});  // Root node has horizontal distance 0

    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        Node* nd = it.first;
        int cl = it.second;
        
        // Update the map with the bottom-most node at each horizontal level
        mp[cl] = nd->data;

        if (nd->left) q.push({nd->left, cl - 1});
        if (nd->right) q.push({nd->right, cl + 1});
    }

    vector<int> ans;
    vector<pair<int, int>> sorted_map(mp.begin(), mp.end());
    sort(sorted_map.begin(), sorted_map.end());  // Sort by horizontal distance

    for (auto it : sorted_map) {
        ans.push_back(it.second);
    }

    return ans;
}
