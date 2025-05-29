// https://leetcode.com/problems/subtree-of-another-tree/submissions/1405780411/

bool isSame(TreeNode* p , TreeNode* q){
    // base 
    if(!p && !q){
        return true;
    } else if((p && !q) ||(q && !p)){
        return false;
    }

    // hypothesis 
    bool left = isSame(p->left, q->left);
    bool right = isSame(p->right, q->right);

    return left && right && (p->val == q->val) ;
}
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(root == NULL && subRoot == NULL || root != NULL && subRoot == NULL){
        return true;
    } else if(root == NULL && subRoot != NULL){
        return false;
    }

    bool left = isSubtree(root->left, subRoot);
    bool right = isSubtree(root->right, subRoot);

    if((root->val == subRoot->val && isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right)) || left || right){
        return true;
    }

    return false;
}