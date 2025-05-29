// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

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
        TreeNode* helper(unordered_map<int, int> &inorderMap, vector<int> &inorder, vector<int> &postorder, int inorderStart, int inorderEnd, int postorderStart, int postorderEnd){
            if(inorderStart > inorderEnd || postorderStart > postorderEnd){
                return NULL;
            }
    
            cout << "end" << postorderEnd << endl;
    
            int elem = postorder[postorderEnd];
            cout << "elem" << elem << endl;
            int idx = inorderMap[elem];
            cout << "idx" << idx << endl;
            TreeNode* root = new TreeNode(elem);
            int numsLeft = idx - inorderStart;
            cout << "numsleft" << numsLeft << endl;
    
            root->left = helper(inorderMap, inorder, postorder, inorderStart, idx-1, postorderStart, postorderStart+numsLeft-1);
    
            root->right = helper(inorderMap, inorder, postorder, idx+1, inorderEnd, postorderStart+numsLeft, postorderEnd-1);
    
            return root;
        }
    public:
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            int n = inorder.size();
    
            if(n == 0){
                return NULL;
            }
    
            if(n == 1){
                TreeNode* root = new TreeNode(inorder[0]);
                return root;
            }
    
            unordered_map<int,int>inorderMap;
    
            for(int i = 0; i<n;i++){
                inorderMap[inorder[i]] = i;
            }
    
            return helper(inorderMap, inorder, postorder, 0, n-1, 0, n-1);
        }
    };