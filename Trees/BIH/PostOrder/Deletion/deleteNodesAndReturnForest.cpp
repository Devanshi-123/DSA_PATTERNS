// https://leetcode.com/problems/delete-nodes-and-return-forest/submissions/1600938472/

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
        TreeNode* postOrderTraversal(TreeNode* root, unordered_map<int,int> &toDeleteMap, vector<TreeNode*> &forest){
            // L R P 
            if(root == NULL){
                return NULL;
            }
    
            
            root->left = postOrderTraversal(root->left, toDeleteMap, forest);
    
            root->right = postOrderTraversal(root->right, toDeleteMap, forest);
    
            // if we need to delete the root then push its subtree in the forest 
            if(toDeleteMap.find(root->val) != toDeleteMap.end()){
                if(root->left){
                    forest.push_back(root->left);
                }
                if(root->right){
                    forest.push_back(root->right);
                }
                return NULL;
            }
    
            return root;
    
        }
        vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
            int n = to_delete.size();
    
            vector<TreeNode*>forest;
    
            if(n == 0){
                forest.push_back(root);
                return forest;
            }
    
            if(root == NULL){
                return forest;
            }
    
            unordered_map<int,int>toDeleteMap;
            for(int i = 0; i<n;i++){
                toDeleteMap[to_delete[i]] = 1;
            }
    
            // if we do not delete the root
            if(postOrderTraversal(root, toDeleteMap, forest)){
                forest.push_back(root);
            }
    
            return forest;
    
    
        }
    };