// https://leetcode.com/problems/cousins-in-binary-tree/submissions/1624457103/

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
        bool isCousins(TreeNode* root, int x, int y) {
            // unique values 
            if(root == NULL){
                return false;
            }
            unordered_map<int,pair<int,int>>levelMap;
            queue<TreeNode*>q;
    
            q.push(root);
            int level = 0;
            levelMap[root->val] = {-1, 0};
    
            while(!q.empty()){
                int n = q.size();
                for(int i = 0; i<n;i++){
                    TreeNode* node = q.front();
                    q.pop();
                    if(node->left){
                        q.push(node->left);
                        levelMap[node->left->val] = {node->val, level+1};
                    }
                    if(node->right){
                        q.push(node->right);
                        levelMap[node->right->val] = {node->val, level+1};
                    }
                }
                level++;
            }
    
            if(levelMap[x].second == levelMap[y].second && levelMap[x].first != levelMap[y].first){
                return true;
            }
    
            return false;
        }
    };

// Variation : Replace every nodes value with the sum of its cousins 

// https://leetcode.com/problems/cousins-in-binary-tree-ii/submissions/1624842032/

// find the level sum ans then to find sum of cousins for each parent some of its children and the replace there value with levelSum - parentsum

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
        vector<int> findLevelSum(TreeNode* root){
            vector<int>levelSum;
            if(root == NULL){
                return levelSum;
            }
    
            queue<TreeNode*>q;
            q.push(root);
            int level = 0;
    
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
                levelSum.push_back(sum);
            }
    
            return levelSum;
        }
    public:
        TreeNode* replaceValueInTree(TreeNode* root) {
            if(root == NULL){
                return NULL;
            }
    
            vector<int>levelSum = findLevelSum(root);
            queue<TreeNode*>q;
    
            q.push(root);
            int level = 1;
            while(!q.empty()){
                int n = q.size();
                for(int i = 0; i<n;i++){
                    TreeNode* node = q.front();
                    q.pop();
                    int parentSum = 0;
                    if(node->left){
                        q.push(node->left);
                        parentSum += node->left->val;
                    }
                    if(node->right){
                        q.push(node->right);
                        parentSum += node->right->val;
                    }
                    if(node->left){
                        node->left->val = levelSum[level] - parentSum;
                    }
                    if(node->right){
                        node->right->val = levelSum[level] - parentSum;
                    }
                }
                level++;
            }
            root->val = 0;
    
            return root;
        }
    };