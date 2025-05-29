

bool isLeaf(TreeNode* root){
        if(!root->left && !root->right){
            return true;
        }

        return false;
    }
    pair<int,int> helper(TreeNode* root){
        // base case 
        if(root == NULL){
            return {0,0};
        }

        // if leaf 
        if(isLeaf(root)){
            return {root->val, 0};
        }

        // induction 
        pair<int,int>leftSubTreeSum = helper(root->left);
        pair<int,int>rightSubTreeSum = helper(root->right);

        int currNodeIncluded = root->val + leftSubTreeSum.second + rightSubTreeSum.second;
        int currNodeExcluded = max(leftSubTreeSum.first + rightSubTreeSum.first, 
                                max(leftSubTreeSum.first + rightSubTreeSum.second, 
                                max(leftSubTreeSum.second + rightSubTreeSum.first, 
                                    leftSubTreeSum.second + rightSubTreeSum.second)));

        return {currNodeIncluded, currNodeExcluded};
    }
    int rob(TreeNode* root) {
        // dp on trees 

        // base case 
        if(root == NULL){
            return 0;
        }

        pair<int,int>p = helper(root);

        return max(p.first, p.second);
    }