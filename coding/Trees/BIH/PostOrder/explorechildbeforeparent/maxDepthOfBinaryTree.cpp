// https://leetcode.com/problems/maximum-depth-of-binary-tree/

int maxDepth(TreeNode* root) {
    // postorder traversal 
    // explore child before parent
    // base 
    if(root == NULL){
        return 0;
    }

    if(!root->left && !root->right){
        return 1;
    }

    // induvtion 
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    // hypothesis
    return 1+max(leftDepth, rightDepth);
}