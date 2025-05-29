// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

// O(n) time and O(n) space

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    if(root == NULL || root == p || root == q){
        return root;
    }

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if(left != NULL && right != NULL){
        return root;
    }

    return (left != NULL) ? left : right;
}