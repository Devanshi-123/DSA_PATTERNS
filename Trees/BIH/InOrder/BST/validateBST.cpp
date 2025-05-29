// https://leetcode.com/problems/validate-binary-search-tree/description/

// do inorder traversal and check if the elements are in sorted order

// O(n) time and O(n) space

void helper(Node* root, vector<int>&vec){
    if(root == NULL){
        return;
    }

    helper(root->left, vec);
    vec.push_back(root->data);
    helper(root->right, vec);
}
bool checkBST(Node* root) {
   vector<int>inorderVec;

   if(root == NULL || !root->left && !root->right){
    return true;
   }

   helper(root, inorderVec);

   int n = inorderVec.size();

   for(int i=0;i<n-1;i++){
    if(inorderVec[i] >= inorderVec[i+1]){
        return false;
    }
   }

    return true;

}

// Variation : Kth Smallest element in BST
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/1625725403/

void helper(TreeNode* root, vector<int>&vec){
    if(root == NULL){
        return;
    }

    helper(root->left, vec);
    vec.push_back(root->val);
    helper(root->right, vec);
}
    int kthSmallest(TreeNode* root, int k) {
        vector<int>inorderVec;

        if(root == NULL){
            return -1;
        }

        helper(root, inorderVec);

        int n = inorderVec.size();

        return inorderVec[k-1];
    }