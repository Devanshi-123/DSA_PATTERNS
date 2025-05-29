
// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/
class Solution {
public:
long long kthLargestLevelSum(TreeNode* root, int k) {
    if(root == NULL){
        return -1;
    }

    vector<long long>levelSum;
    queue<TreeNode*>q;

    q.push(root);

    while(!q.empty()){
        int n = q.size();
        long long sum = 0;

        for(int i = 0; i<n;i++){
            TreeNode* node = q.front();
            q.pop();
            sum += node->val;
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        levelSum.push_back(sum);
    }

    if(levelSum.size() < k){
        return -1;
    }

    sort(levelSum.begin(), levelSum.end());

    return levelSum[levelSum.size()-k];
}
};