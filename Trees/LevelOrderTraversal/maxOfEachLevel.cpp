// https://leetcode.com/problems/find-largest-value-in-each-tree-row/submissions/1624305840/

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
        vector<int> largestValues(TreeNode* root) {
            vector<int>largestElem;
            if(root == NULL){
                return largestElem;
            }
    
            queue<TreeNode*>q;
            q.push(root);
    
            while(!q.empty()){
                int n = q.size();
                int maxElem = INT_MIN;
                for(int i = 0; i<n;i++){
                    TreeNode* node = q.front();
                    maxElem = max(maxElem , node->val);
                    if(node->left){
                        q.push(node->left);
                    }
                    if(node->right){
                        q.push(node->right);
                    }
                    q.pop();
                }
                largestElem.push_back(maxElem);
            }
    
            return largestElem;
        }
    };