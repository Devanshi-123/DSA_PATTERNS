// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

// time complexity is O(h) where h is the height of the tree : O(n) in the worst case   

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if((p->val < root->val && q->val > root->val) || (p->val > root->val && q->val < root->val) || (p->val == root->val) || (q->val == root->val)){
        return root;
    }else if(p->val < root->val && q->val < root->val){
        return lowestCommonAncestor(root->left, p, q);
    }else {
        return lowestCommonAncestor(root->right, p, q);
    }
    return NULL;
}