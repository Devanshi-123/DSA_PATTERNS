// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/submissions/1625047529/


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
    private:
        void preorderTraversal(TreeNode* root, TreeNode* &node){
            if(root == NULL){
                return;
            }
    
            // parent 
             cout << "val" << root->val << endl;
            TreeNode* rightNode = root->right;
            node->right = root;
            node->left = NULL;
            node = root;
           
            // left 
            preorderTraversal(root->left, node);
            // right 
            preorderTraversal(rightNode, node);
    
            return;
        }
    public:
        void flatten(TreeNode* root) {
            // base case 
            if(root == NULL || (!root->left && !root->right)){
                return;
            }
    
            TreeNode* node = new TreeNode();
            preorderTraversal(root, node);
            return;
        }
    };