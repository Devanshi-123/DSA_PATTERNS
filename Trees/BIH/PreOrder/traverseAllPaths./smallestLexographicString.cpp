// https://leetcode.com/problems/smallest-string-starting-from-leaf/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;urk`w1   q
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void helper(TreeNode* root, vector<string> &paths, string pathString){
        // bases case 
        if(root == NULL){
            return;
        }

        pathString += root->val + 'a';

        // leaf nde ": cond case "
        if(root->left == NULL && root->right == NULL){
            reverse(pathString.begin(), pathString.end());
            paths.push_back(pathString);
        }

        // explore choices 
        if(root->left){
            helper(root->left, paths, pathString);
        }
        if(root->right){
            helper(root->right, paths, pathString);
        }
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        // dfs 
        // preorder 

        string smallestString = "";
        if(root == NULL){
            return smallestString;
        }
        if(root->left == NULL && root->right == NULL){
            smallestString += root->val + 'a';
            return smallestString;
        }

        vector<string>paths;
        string pathString = "";

        helper(root, paths, pathString);
        sort(paths.begin(), paths.end());
        return paths[0];
    }
};