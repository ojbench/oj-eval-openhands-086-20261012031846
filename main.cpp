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

// Function to get nodes at a specific depth
void getNodesAtDepth(TreeNode* root, int targetDepth, int currentDepth, vector<TreeNode*>& nodes) {
    if (root == nullptr) return;
    
    if (currentDepth == targetDepth) {
        nodes.push_back(root);
        return;
    }
    
    getNodesAtDepth(root->left, targetDepth, currentDepth + 1, nodes);
    getNodesAtDepth(root->right, targetDepth, currentDepth + 1, nodes);
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
    
    int t;
    cin >> t;
    
    // Process each query
    for (int i = 0; i < t; i++) {
        int k;
        cin >> k;
        
        // Find all nodes at depths that are multiples of k
        for (int depth = k; depth <= n; depth += k) {
            vector<TreeNode*> nodesAtDepth;
            getNodesAtDepth(nodes[1], depth, 1, nodesAtDepth);
            
            // Swap children for each node at this depth
            for (TreeNode* node : nodesAtDepth) {
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