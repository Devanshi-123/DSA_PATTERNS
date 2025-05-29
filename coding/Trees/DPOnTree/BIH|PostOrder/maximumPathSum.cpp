// https://leetcode.com/problems/binary-tree-maximum-path-sum/

int ans = INT_MIN;
    int helper(TreeNode* root, int &maxPathSum){
        // base case 
        if(root == NULL){
            return 0;
        }

        // left 
        int leftVal = helper(root->left, maxPathSum);
        // right 
        int rightVal = helper(root->right, maxPathSum);

        // since we can only pass max value from one branch to the parent 
        int temp = max(root->val, max(leftVal, rightVal)+root->val);
        // but we need to store the maxm of the whole path including both branches or single branch whatever is max 
        ans = max(temp, leftVal+rightVal+root->val);
        maxPathSum = max(maxPathSum, ans);
        return temp;

    }
    int maxPathSum(TreeNode* root) {
        // max path sum from any node to any node 
        // dp on tree as otherwise it will be n^2

        if(root == NULL){
            return 0;
        }

        if(!root->left && !root->right){
            return root->val;
        }

        int maxPathSum = INT_MIN;
        helper(root, maxPathSum);

        return maxPathSum;
    }