// https://leetcode.com/problems/distribute-coins-in-binary-tree/submissions/1625889259/

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
        int helper(TreeNode* root, int &minMoves){
            // base case 
            if(root == NULL){
                return 0;
            }
    
            // left and right child
            int leftVal = helper(root->left, minMoves);
            int rightVal = helper(root->right, minMoves);
    
            // parent
            minMoves += abs(leftVal)+abs(rightVal);
    
            // every node will return whatever it has extra other than 1 to its parent
            return root->val + leftVal + rightVal -1;
    
        }
        int distributeCoins(TreeNode* root) {
            // root 
            // n nodes and n coins 
            // node->val => coins in each node 
            // sum of val of all nodes = n 
    
            // if start traversal from leaf node -> postorder 
            // if start traversal from root -> preorder 
    
            if(root == NULL){
                return 0;
            }
    
            if(!root->left && !root->right){
                return 0;
            }
    
            int moves = 0;
    
            int minMoves = 0;
    
            helper(root, minMoves);
    
            return minMoves;
        }
    };