  int result=0;
 int solve(Node* root) {
        if (!root) return 0;  // Base case: If node is NULL, height is 0

        int leftHeight = solve(root->left);
        int rightHeight = solve(root->right);

        // Update result with the maximum diameter found so far
        result = max(result, leftHeight + rightHeight);

        // Return height of current node
        return max(leftHeight, rightHeight) + 1;
    }

    int diameter(Node* root) {
        solve(root);
        return result;  // Diameter is stored in `result`
    }
