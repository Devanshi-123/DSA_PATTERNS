// https://leetcode.com/problems/find-bottom-left-tree-value/?envType=problem-list-v2&envId=tree

 int findHeight(TreeNode* root) {
	if(root == NULL) {
		return 0;
	}

	if(root->left == NULL && root->right == NULL) {
		return 1;
	}

	int leftHeight = findHeight(root->left);
	int rightHeight = findHeight(root->right);
	
	return max(leftHeight, rightHeight) + 1;
}
 
int findBottomLeftValue(TreeNode* root) {
      	queue<TreeNode*>q;

	q.push(root);

	int height = findHeight(root);
	int level = 1;
	
	while(!q.empty()) {
		int n = q.size();
		for(int i = 0; i<n;i++) {
			TreeNode* node = q.front();
			q.pop();
			if(level == height && i == 0){
				return node->val;
			}
			if(node->left != NULL){
				q.push(node->left);
			}
			if(node->right != NULL) {
				q.push(node->right);
			}
		}
		level++;
   	}

	return -1;
}