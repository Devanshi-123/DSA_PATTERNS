// https://leetcode.com/problems/balanced-binary-tree/


int height(TreeNode* root){
    if(root == NULL){
        return 0;
    }

    if(!root->left && !root->right){
        return 1;
    }

    int leftVal = height(root->left);
    int rightVal = height(root->right);

    return max(leftVal, rightVal)+1;
}
bool isBalanced(TreeNode* root) {
    if(root == NULL){
        return true;
    }

    if(!root->left && !root->right){
        return true;
    }

    bool leftVal = isBalanced(root->left);
    bool rightVal = isBalanced(root->right);

    return leftVal && rightVal && (abs(height(root->left) - height(root->right)) <= 1);

}