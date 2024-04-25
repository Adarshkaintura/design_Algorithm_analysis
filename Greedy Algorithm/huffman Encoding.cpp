#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void traverse(node* root, vector<string>& ans, string temp) {
    if (root->left == nullptr && root->right == nullptr) {
        ans.push_back(temp);
        return;
    }
    traverse(root->left, ans, temp + '0');
    traverse(root->right, ans, temp + '1');
}

class cmp {
public:
    bool operator()(node* a, node* b) {
         return a->data > b->data;
    }
};

class Solution {
public:
    vector<string> huffmanCodes(string& s, vector<int>& freq, int n) {
        sort(freq.begin(), freq.end());
        priority_queue<node*, vector<node*>, cmp> minh;
        for (int i = 0; i < n; i++) {
            node* newnode = new node(freq[i]);
            minh.push(newnode);
        }
        while(minh.size>1) {
            node* temp1 = minh.top();
            minh.pop();
            node* temp2 = minh.top();
            minh.pop();
            node* newnode = new node(temp1->data + temp2->data);
            newnode->left = temp1;
            newnode->right = temp2;
            minh.push(newnode);
        }
        vector<string> ans;
        traverse(minh.top(), ans, "");
        return ans;
    }
};
