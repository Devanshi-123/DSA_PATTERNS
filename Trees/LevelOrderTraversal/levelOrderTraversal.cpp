// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>>traversal;
            if(root == NULL){
                return traversal;
            }
    
            queue<TreeNode*>q;
            q.push(root);
    
            while(!q.empty()){
                int n = q.size();
                vector<int>level;
                for(int i = 0; i<n;i++){
                    TreeNode* node = q.front();
                    level.push_back(node->val);
    
                    if(node->left){
                        q.push(node->left);
                    }
                    if(node->right){
                        q.push(node->right);
                    }
                    q.pop();
                }
                traversal.push_back(level);
            }
    
            return traversal;
        }
    };