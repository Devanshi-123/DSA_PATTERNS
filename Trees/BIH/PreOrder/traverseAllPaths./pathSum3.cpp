// https://leetcode.com/problems/path-sum-iii/

// maxm path sum from any node to any node downwards

void helper(TreeNode* root, int &count,long long pathSum, int targetSum){
    if(root == NULL){
        return;
    }
    
    // parent
    pathSum += root->val;

    if(pathSum == targetSum){
        count++;
    }

    if(!root->left && !root->right){
        return;
    }

    helper(root->left, count, pathSum, targetSum);
    helper(root->right, count,pathSum,  targetSum);
}
int pathSum(TreeNode* root, int targetSum) {
    // two times preorder 
    // since we can only go downward 
    if(root == NULL){
        return 0;
    }

    if(!root->left && !root->right){
        if(targetSum == root->val){
            return 1;
        }else {
            return 0;
        }
    }

    int count = 0;

    // num of paths starting from this root that have sum equal to targetsum
    helper(root, count, 0, targetSum);

    cout << "val" << root->val << endl;
    cout << "val count" << count << endl;

    return count + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
}