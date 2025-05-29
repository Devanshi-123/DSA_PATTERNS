// https://leetcode.com/problems/most-frequent-subtree-sum/description/

int helper(TreeNode* root, unordered_map<int,int> &freqMap){
    if(root == NULL){
        return 0;
    }

    if(!root->left && !root->right){
        if(freqMap.find(root->val) == freqMap.end()){
            freqMap[root->val] = 1;
        }else{  
            freqMap[root->val]++;
        }
        return root->val;
    }

    int leftSubtreeSum = helper(root->left, freqMap);
    int rightSubtreeSum = helper(root->right, freqMap);

    int tempSum = root->val + leftSubtreeSum + rightSubtreeSum;

    if(freqMap.find(tempSum) == freqMap.end()){
        freqMap[tempSum] = 1;
    }else{  
        freqMap[tempSum]++;
    }

    return tempSum;
}
vector<int> findFrequentTreeSum(TreeNode* root) {

    vector<int>vec;

    if(root == NULL){
        return vec;
    }

    if(!root->left && !root->right){
        vec.push_back(root->val);
        return vec;
    }

    unordered_map<int,int>freqMap;
    helper(root, freqMap);

    int maxFreq = 0;

    for(auto it = freqMap.begin(); it!= freqMap.end(); it++){
        if(it->second > maxFreq){
            maxFreq = it->second;
        }
    }

    for(auto it = freqMap.begin(); it!= freqMap.end(); it++){
        if(it->second == maxFreq){
            vec.push_back(it->first);
        }
    }

    return vec;

}       