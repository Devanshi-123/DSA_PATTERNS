// https://leetcode.com/problems/path-sum/submissions/1626578260/

void helper(TreeNode* root, int targetSum, int pathSum, bool &hasPath){
    if(root == NULL){
        return;
    }
    pathSum += root->val;

    if(!root->left && !root->right){
        if(pathSum == targetSum){
            hasPath = true;
            return;
        }
        return;
    }

    helper(root->left, targetSum, pathSum, hasPath);
    helper(root->right, targetSum, pathSum, hasPath);
}
bool hasPathSum(TreeNode* root, int targetSum) {
    if(root == NULL){
        return false;
    }
    bool hasPath = false;
    helper(root, targetSum, 0, hasPath);

    return hasPath;
}