// https://leetcode.com/problems/recover-binary-search-tree/?envType=problem-list-v2&envId=tree

// Time Complexity: O(n)
// Space Complexity: O(n) inorder traversal

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
    void inorderTraversal(TreeNode* root, vector<int> &inorder){
        if(root == NULL){
            return;
        }

        if(!root->left && !root->right) {
            inorder.push_back(root->val);
            return;
        }

        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }

    void recoverTraversal(TreeNode* root, vector<int> &swapVal, int n){
        if(root == NULL){
            return;
        }

        if(root->val == swapVal[0] ){
            root->val = swapVal[n-1];
        }else if(root->val == swapVal[n-1]){
            root->val = swapVal[0];
        }

        if(!root->left && !root->right) {
            return;
        }

        recoverTraversal(root->left, swapVal, n);
        recoverTraversal(root->right, swapVal, n);
    }

void recoverTree(TreeNode* root) {
    // inorder traversal 
    vector<int>inorder;
    if(root == NULL) {
    return;
    }

    inorderTraversal(root, inorder);

    int numNodes = inorder.size();

    vector<int>swapVal;

    for(int i = 0; i < numNodes-1; i++) {
        if(inorder[i] > inorder[i+1]){
            swapVal.push_back(inorder[i]);
            swapVal.push_back(inorder[i+1]);
        }
    }

    int n = swapVal.size();

    if(n == 0){
        return;
    }

    recoverTraversal(root, swapVal, n);

}

};


// Without using extra space

// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree

// Approach: Morris Traversal
// 1. Find the inorder predecessor of the current node.
// 2. If the predecessor's right child is null, set it to the current node and move to the left child.
// 3. If the predecessor's right child is the current node, revert the changes made in step 2 and move to the right child.
// 4. If the current node's value is greater than the next node's value, mark the nodes to be swapped.
// 5. Finally, swap the values of the two marked nodes to recover the BST.