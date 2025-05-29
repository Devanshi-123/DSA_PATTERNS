// https://leetcode.com/problems/longest-univalue-path/

int ans = INT_MIN;
pair<int,int> helper(TreeNode* root, int &longestPath){
    // base
    if(root == NULL){
        return {0,0};
    }

    if(!root->left && !root->right){
        return {1, root->val};
    }


    // induction 
    pair<int, int> leftVal= helper(root->left, longestPath);
    pair<int, int> rightVal = helper(root->right, longestPath);

    // hypothesis
    int temp = 0;
    if(root->val == leftVal.second && root->val == rightVal.second){
        temp = max(leftVal.first, rightVal.first)+1;
        ans = max(ans, leftVal.first + rightVal.first + 1);
    }else if(root->val == leftVal.second){
        temp = leftVal.first + 1;
        ans = max(ans, leftVal.first + 1);
    }else if(root->val == rightVal.second){
        temp = rightVal.first + 1;
        ans = max(ans, rightVal.first + 1);
    }else {
        temp = 1;
        ans = max(ans, max(max(leftVal.first, rightVal.first), 1));
    }

    longestPath = max(longestPath, ans);
    return {temp, root->val};
}
int longestUnivaluePath(TreeNode* root) {
    // since this path may or may not pass from the root 
    // it can be from any source to any 
    // optimal : dp 

    // bih or postorder 
    if(root == NULL){
        return 0;
    }

    int longestPath = 0;

    helper(root, longestPath);

    if(longestPath == 0){
        return 0;
    }

    return longestPath-1;
}