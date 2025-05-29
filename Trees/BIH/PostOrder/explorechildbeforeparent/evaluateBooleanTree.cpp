// https://leetcode.com/problems/evaluate-boolean-binary-tree/

// O(n) time and O(n) space

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
        bool evaluateTree(TreeNode* root) {
            // postorder traversal : since we want to evaluate children first then parent 
            // bih 
            // leaf node 
            if(!root->left && !root->right){
                if(root->val == 1){
                    return true;
                }else {
                    return false;
                }
            }
    
            int leftVal = evaluateTree(root->left);
            int rightVal = evaluateTree(root->right);
    
            if(root->val == 2){
                return leftVal || rightVal;
            }else {
                return leftVal && rightVal;
            }
        }
    };