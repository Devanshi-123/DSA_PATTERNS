// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/

pair<int,int> helper(TreeNode* root, int &count){
    // postorder traversal
    // return pair of sum and num of nodes
    // base 
    if(root == NULL){
        return {0,0};
    }

    // leaf node
    if(!root->left && !root->right){
        count++;
        return {root->val, 1};
    }

    // explore left and right
    pair<int,int>leftPair = helper(root->left, count);
    pair<int,int>rightPair = helper(root->right, count);

    // parent 
    int totalSum = leftPair.first + rightPair.first + root->val;
    int totalNum = leftPair.second + rightPair.second + 1;
    int avg = totalSum/totalNum;
    if(avg == root->val){
        count++;
    }

    return {totalSum, totalNum};
}
public:
int averageOfSubtree(TreeNode* root) {
    // root 
    // number of nodes : value == avg of values in its subtree 
    if(root == NULL){
        return 0;
    }

    if(!root->left && !root->right){
        return 1;
    }

    int count = 0;
    helper(root, count);

    return count;
}