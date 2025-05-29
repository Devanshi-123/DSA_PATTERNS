// https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    private:
        void helper(TreeNode* root, vector<int> &traversal){
            if(root == NULL){
                return;
            }
    
            // left 
            helper(root->left, traversal);
            // parent
            traversal.push_back(root->val);
            // right 
            helper(root->right, traversal);
        }
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int>traversal;
            if(root == NULL){
                return traversal;
            }
    
            helper(root, traversal);
    
            return traversal;
        }
    };