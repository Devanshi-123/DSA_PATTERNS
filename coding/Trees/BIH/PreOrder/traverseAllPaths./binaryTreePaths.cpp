// https://leetcode.com/problems/binary-tree-paths/description/
// O(n*h) time and O(n*h) space
// h is the height of the tree
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
        void helper(vector<string> &paths, string pathString, TreeNode* root){
            if(root == NULL){
                return;
            }
    
            pathString += to_string(root->val) + "->";
    
            if(root->left == NULL && root->right == NULL){
                pathString.pop_back();
                pathString.pop_back();
                paths.push_back(pathString);
                return;
            }
    
            helper(paths, pathString, root->left);
             helper(paths, pathString, root->right);
        }
    public:
        vector<string> binaryTreePaths(TreeNode* root) {
            vector<string>paths;
            string pathString = "";
    
            if(root == NULL){
                return paths;
            }
    
            if(root->left == NULL && root->right == NULL){
                paths.push_back(to_string(root->val));
                return paths;
            }
    
            helper(paths, pathString, root);
    
            return paths;
        }
    };