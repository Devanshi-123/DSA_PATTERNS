// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>>traversal;
    
            if(root == NULL){
                return traversal;
            }
    
            queue<TreeNode*>q;
    
            q.push(root);
            bool ltr = true;
    
            while(!q.empty()){
                int n = q.size();
                vector<int>vec;
                stack<int>st;
                for(int i = 0; i<n;i++){
                    TreeNode* node = q.front();
                    if(ltr){
                        vec.push_back(node->val);
                    }else {
                        st.push(node->val);
                    }
                    if(node->left){
                        q.push(node->left);
                    }
                    if(node->right){
                        q.push(node->right);
                    }
                    q.pop();
                }
                ltr = !ltr;
                while(!st.empty()){
                    vec.push_back(st.top());
                    st.pop();
                }
                traversal.push_back(vec);
            }
    
            return traversal;
        }
    };