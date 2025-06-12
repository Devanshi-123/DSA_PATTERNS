void helper(Node* root, int num, int &ans){
    if(root == NULL){
        return;
    }

    if(num <= root->key){
        helper(root->left, num, ans);
    }else {
        ans = max(ans, root->key);
        helper(root->right, num, ans);
    }
}
int findLargestSmallerKey(Node *rootNode, int num) 
{
  // your code goes here

  if(rootNode == NULL){
    return -1;
  }

    int ans = -1;
    helper(rootNode, num, ans);
    return ans;
}