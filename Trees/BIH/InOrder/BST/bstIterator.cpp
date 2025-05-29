// https://leetcode.com/problems/binary-search-tree-iterator/description/

// O(n) time and O(n) space

class BSTIterator {
    public:
        // define data members
        vector<int>traversal;
        int i;
        int n;
        BSTIterator(TreeNode* root) {
            i = -1;
            inorderTraversal(root, traversal);
            n = traversal.size();
        }
        
        int next() {
            i++;
            return traversal[i];
        }
        
        bool hasNext() {
            if(i+1 < n){
                return true;
            }
            return false;
        }
    
        void inorderTraversal(TreeNode* root, vector<int> &traversal){
            if(root == NULL){
                return;
            }
    
            inorderTraversal(root->left, traversal);
            traversal.push_back(root->val);
            inorderTraversal(root->right, traversal);
        }
    };