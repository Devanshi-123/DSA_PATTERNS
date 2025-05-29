// https://leetcode.com/problems/symmetric-tree/

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
        bool isSymm(TreeNode* p, TreeNode* q){
           if(!p && !q){
            return true;
           }else if((!p && q) ||(p && !q)){
            return false;
           }
    
           return p->val == q->val && isSymm(p->left, q->right) && isSymm(p->right, q->left);
        }
    public:
        bool isSymmetric(TreeNode* root) {
            // base case 
            if(root == NULL || (!root->left && !root->right)){
                return true;
            }else if((!root->left && root->right) || (root->left && !root->right)){
                return false;
            }
    
            return isSymm(root->left, root->right);
        }
    };