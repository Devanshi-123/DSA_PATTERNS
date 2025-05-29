// 

void inorderTraversal(TreeNode* root, vector<int> &traversal){
    if(root == NULL){
        return;
    }
    if(!root->left && !root->right){
        traversal.push_back(root->val);
        return;
    }

    inorderTraversal(root->left, traversal);
    traversal.push_back(root->val);
    inorderTraversal(root->right, traversal);
}
public:
int getMinimumDifference(TreeNode* root) {
    if(root == NULL || (!root->left && !root->right)){
        return 0;
    }

    vector<int>traversal;
    inorderTraversal(root, traversal);
    int minDiff = INT_MAX;

    int n = traversal.size();

    for(int i = 0; i<n-1; i++){
        int diff = abs(traversal[i] - traversal[i+1]);
        minDiff = min(minDiff, diff);
    }

    return minDiff;

}