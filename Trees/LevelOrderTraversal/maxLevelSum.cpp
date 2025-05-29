// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

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
        int maxLevelSum(TreeNode* root) {
            int level = 1;
            if(root == NULL){
                return 0;
            }
            int maxLevel = -1;
    
            int maxSum = INT_MIN;
    
            queue<TreeNode*>q;
            q.push(root);
    
            while(!q.empty()){
                int n = q.size();
                int sum = 0;
    
                for(int i = 0; i<n;i++){
                    TreeNode* node = q.front();
                    q.pop();
                    sum += node->val;
                    if(node->left){
                        q.push(node->left);
                    }
                    if(node->right){
                        q.push(node->right);
                    }
                }
                if(sum > maxSum){
                    maxSum = sum;
                    maxLevel = level;
                }
                level++;
            }
    
            return maxLevel;
        }
    };