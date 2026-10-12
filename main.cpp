#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to perform inorder traversal
void inorder(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;
    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
}

// Function to swap left and right children of a node
void swapChildren(TreeNode* node) {
    if (node == nullptr) return;
    TreeNode* temp = node->left;
    node->left = node->right;
    node->right = temp;
}

int main() {
    int n;
    cin >> n;
    
    // Create nodes
    vector<TreeNode*> nodes(n + 1);
    for (int i = 1; i <= n; i++) {
        nodes[i] = new TreeNode(i);
    }
    
    // Read children information
    for (int i = 1; i <= n; i++) {
        int left, right;
        cin >> left >> right;
        
        if (left != -1) {
            nodes[i]->left = nodes[left];
        }
        if (right != -1) {
            nodes[i]->right = nodes[right];
        }
    }
    
    // Precompute depth of each node and group nodes by depth
    vector<int> depth(n + 1, 0);
    vector<vector<TreeNode*>> nodesAtDepth(n + 1);  // nodesAtDepth[i] contains all nodes at depth i
    
    // BFS to compute depths and group nodes
    queue<TreeNode*> q;
    q.push(nodes[1]);
    depth[1] = 1;
    nodesAtDepth[1].push_back(nodes[1]);
    
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        
        // Get the index of current node (value is the index)
        int idx = curr->val;
        
        // Process left child
        if (curr->left != nullptr) {
            int leftIdx = curr->left->val;
            depth[leftIdx] = depth[idx] + 1;
            nodesAtDepth[depth[leftIdx]].push_back(curr->left);
            q.push(curr->left);
        }
        
        // Process right child
        if (curr->right != nullptr) {
            int rightIdx = curr->right->val;
            depth[rightIdx] = depth[idx] + 1;
            nodesAtDepth[depth[rightIdx]].push_back(curr->right);
            q.push(curr->right);
        }
    }
    
    int t;
    cin >> t;
    
    // Process each query
    for (int i = 0; i < t; i++) {
        int k;
        cin >> k;
        
        // Find all nodes at depths that are multiples of k
        for (int depthLevel = k; depthLevel <= n; depthLevel += k) {
            // Swap children for each node at this depth
            for (TreeNode* node : nodesAtDepth[depthLevel]) {
                swapChildren(node);
            }
        }
        
        // Perform inorder traversal and output result
        vector<int> result;
        inorder(nodes[1], result);
        
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    // Clean up memory
    for (int i = 1; i <= n; i++) {
        delete nodes[i];
    }
    
    return 0;
}