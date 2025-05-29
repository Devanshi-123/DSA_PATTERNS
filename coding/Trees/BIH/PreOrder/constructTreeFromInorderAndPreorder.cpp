// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
        TreeNode* helper(unordered_map<int,int> &inorderMap, vector<int> &inorder, vector<int> &preorder, int n, int preorderStart, int preorderEnd, int inorderStart, int inorderEnd){
            // base case
            if(preorderEnd < preorderStart){
                return NULL;
            }
            if(inorderEnd < inorderStart){
                return NULL; 
            }
            
            int elem = preorder[preorderStart];
            int elemIdx = inorderMap[elem];
            int numsLeft = elemIdx - inorderStart;
            TreeNode* root = new TreeNode(elem);
    
            root->left = helper(inorderMap, inorder, preorder,n, preorderStart+1, preorderStart+numsLeft, inorderStart, elemIdx-1);
             root->right = helper(inorderMap, inorder, preorder,n, preorderStart+numsLeft+1, preorderEnd, elemIdx+1, inorderEnd);
    
            return root;
        }
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            int n = preorder.size();
            if(n == 0){
                return NULL;
            }
    
            if(n == 1){
                TreeNode* root = new TreeNode(preorder[0]);
                return root;
            }
    
            unordered_map<int,int>inorderMap;
            for(int i = 0; i<n;i++){
                inorderMap[inorder[i]] = i;
            }
            return helper(inorderMap, inorder, preorder, n, 0, n-1, 0, n-1);
        }
    };