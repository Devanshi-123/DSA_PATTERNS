// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

// since we wanted to move back and forth we converted the tree into a graph
// and then used dfs to find the nodes at distance k

void dfs(unordered_map<int, vector<int>> &adjList, vector<int> &ans, int src, unordered_map<int, int> &vis, int pathCount, int k){
    cout << "src" << src << endl;
    cout << "pc" << pathCount << endl;
    vis[src] = 1;

    if(pathCount == k){
        ans.push_back(src);
        return;
    }

    for(auto neigh : adjList[src]){
        cout << "neigh" << neigh << endl;
        if(vis.find(neigh) == vis.end()){
            dfs(adjList, ans, neigh, vis, pathCount+1, k);
        }
    }

    return;
}
void preorder(TreeNode* root, unordered_map<int, vector<int>> &adjList){
    if(root == NULL || (!root->left && !root->right)){
        return;
    }

    if(root->left){
        int u = root->val;
        int v = root->left->val;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    if(root->right){
        int u = root->val;
        int v = root->right->val;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    preorder(root->left, adjList);
    preorder(root->right, adjList);

}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    // two times preorder
    vector<int>ans;
    if(root == NULL){
        return ans;
    }

    unordered_map<int, vector<int>>adjList;
    unordered_map<int, int>vis;

    preorder(root, adjList);
    
    dfs(adjList, ans, target->val, vis, 0, k);

    return ans;
}