// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/

pair<int,int> helper(TreeNode* root, int &longestPath){
    if(root == NULL){
        return {0,0};
    }

    pair<int,int>left = helper(root->left, longestPath);
    pair<int,int>right = helper(root->right, longestPath);

    pair<int,int>temp = {left.second+1, right.first+1};
    longestPath = max(longestPath, max(temp.first, temp.second));

    return temp;
}
int longestZigZag(TreeNode* root) {
    if(root == NULL || (!root->left && !root->right)){
        return 0;
    }

    int longestPath = 0;

    pair<int,int>p = helper(root, longestPath);

    return longestPath-1;
}