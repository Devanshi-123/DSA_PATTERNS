// https://leetcode.com/problems/diameter-of-binary-tree/description/

int ans = INT_MIN;
    int helper(TreeNode* root, int &longestPath){
        if(root == NULL){
            return 0;
        }

        int leftVal = helper(root->left, longestPath);
        int rightVal = helper(root->right, longestPath);


        // as we can only pass result from one branch to parent
        // as there is one edge between the left , right subtree and the current node 
        int temp = max(leftVal, rightVal)+1;
        // considering current nnode as root AS WE ONLY WANT TO COUNT EDGES AND not nodes so do not count current node 
        ans = max(ans, leftVal+rightVal);
        longestPath = max(ans, longestPath);

        return temp;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        // longest path from any node to any node 
        if(root == NULL || (!root->left && !root->right)){
            return 0;
        }

        int longestPath = 0;
        helper(root, longestPath);
        return longestPath;
    }