// https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/

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
        void postOrderTraversal(TreeNode* &root, unordered_map<TreeNode*, int> &sufficientNodes){
            if(root == NULL){
                return;
            }
    
            if(root->left == NULL && root->right == NULL){
                if(sufficientNodes.find(root) == sufficientNodes.end()){
                    cout << "delete val" << root->val << endl;
                    root = NULL;
                }
                return;
            }
    
            postOrderTraversal(root->left, sufficientNodes);
             postOrderTraversal(root->right, sufficientNodes);
    
            if(sufficientNodes.find(root) == sufficientNodes.end()){
                    root = NULL;
            }
            return;
            
        }
        void helper(TreeNode* &root, int sumPath, int limit, vector<TreeNode*> vec, unordered_map<TreeNode*, int> &sufficientNodes){
            if(root == NULL){
                return;
            }
    
            sumPath += root->val;
            vec.push_back(root);
            if(root->left == NULL && root->right == NULL){
                if(sumPath >= limit){
                    for(auto elem : vec){
                        if(sufficientNodes.find(elem) == sufficientNodes.end()){
                            sufficientNodes[elem] = 1;
                        }
                    }
                }
                return;
            }
    
            if(root->left){
                helper(root->left, sumPath, limit, vec, sufficientNodes);
            }
            if(root->right){
                helper(root->right, sumPath, limit, vec, sufficientNodes);
            }
        }
    public:
        TreeNode* sufficientSubset(TreeNode* root, int limit) {
            // delete insuff nodes 
            // inbsuff nodes : all the paths which has this node has sum < limit 
            if(root == NULL){
                return root;
            }
    
            if(root->left == NULL && root->right == NULL){
                if(root->val < limit){
                    root = NULL;
                    return NULL;
                }else {
                    return root;
                }
            }
    
            int sumPath = 0;
            unordered_map<TreeNode*, int>sufficientNodes;
            vector<TreeNode*>vec;
    
            helper(root, sumPath, limit, vec, sufficientNodes);
            for(auto it = sufficientNodes.begin(); it != sufficientNodes.end(); it++){
                cout << "val" << it->first->val;
            }
            postOrderTraversal(root, sufficientNodes);
            return root;
        }
    };