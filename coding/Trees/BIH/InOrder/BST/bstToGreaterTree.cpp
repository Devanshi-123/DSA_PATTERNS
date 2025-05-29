// https://leetcode.com/problems/convert-bst-to-greater-tree/?envType=problem-list-v2&envId=tree

// Time Complexity: O(n)
// Space Complexity: O(n)

void inorderTraversal(TreeNode* root, vector<int> &traversal) {
	if(root == NULL){
		return;
	}
	
	if(root->left == NULL && root->right == NULL) {
		traversal.push_back(root->val);
		return;
	}
	
	inorderTraversal(root->left, traversal);
	traversal.push_back(root->val);
	inorderTraversal(root->right, traversal);
}


void swapValues(TreeNode* root, vector<int> &suffixSum, int &count) {
	if(root == NULL){
		return;
	}
	
	if(root->left == NULL && root->right == NULL) {
		swap(root->val, suffixSum[count]);
		count++;
		return;
	}
	
	swapValues(root->left, suffixSum, count);
	swap(root->val, suffixSum[count]);
	count++;
	swapValues(root->right, suffixSum, count);
}


TreeNode* convertBST(TreeNode* root) {

	if(root == NULL || (root->left == NULL && root->right == NULL)){
		return root;
	}

            // inorder traversal 
	vector<int>inorderVec;
	inorderTraversal(root, inorderVec);
	
	int n = inorderVec.size();
	vector<int>suffixSum(n, 0);
	
	suffixSum[n-1] = inorderVec[n-1];

	for(int i = n-2; i>= 0 ; i--){
		suffixSum[i] = inorderVec[i] + suffixSum[i+1];
	}

    int count = 0;
	swapValues(root, suffixSum, count);

	return root;

   }