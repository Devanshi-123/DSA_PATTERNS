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
vector<int> findMode(TreeNode* root) {
    vector<int>modes;
    if(root == NULL){
        return modes;
    }

    if(!root->left && !root->right){
        modes.push_back(root->val);
        return modes;
    }

    vector<int>traversal;
    inorderTraversal(root, traversal);

    int maxFreq = 0;
    int n = traversal.size();
    unordered_map<int,int>freqMap;
    for(int i = 0; i<n;i++){
        freqMap[traversal[i]]++;
        if(freqMap[traversal[i]] > maxFreq){
            maxFreq = freqMap[traversal[i]];
        }
    }

    for(auto it = freqMap.begin(); it != freqMap.end(); it++){
        if(it->second == maxFreq){
            modes.push_back(it->first);
        }
    }

    return modes;
}