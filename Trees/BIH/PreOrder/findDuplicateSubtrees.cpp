// https://leetcode.com/problems/find-duplicate-subtrees/submissions/1315189396/

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
        string dfs(TreeNode* root, vector<TreeNode*>&res, unordered_map<string,int>&subtrees){
            if(root == NULL){
                return "null";
            }
    
            string str = to_string(root->val) + "," + dfs(root->left, res, subtrees) + "," + dfs(root->right, res, subtrees);
    
            if(subtrees.find(str) != subtrees.end() && subtrees[str] == 1){
                res.push_back(root);
            }
            subtrees[str]++;
            return str;
        }
        vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
            vector<TreeNode*>res;
            unordered_map<string,int>subtrees;
            dfs(root, res, subtrees);
            return res;
        }
    };