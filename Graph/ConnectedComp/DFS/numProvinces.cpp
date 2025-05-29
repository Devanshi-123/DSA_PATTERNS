// https://leetcode.com/problems/number-of-provinces/description/

void dfs(vector<vector<int>> &adjList,vector<int> &vis,int n,int src){
    vis[src] = 1;

    // explore neigh 
    for(auto neigh : adjList[src]){
        if(vis[neigh] == -1){
            dfs(adjList, vis, n, neigh);
        }
    }
}   
int findCircleNum(vector<vector<int>>& isConnected) {
    // adj list from matrux 
    int n = isConnected.size();
    vector<vector<int>>adjList(n+1);
    vector<int>vis(n+1, -1);

    for(int i = 0; i<n;i++){
        for(int j = 0;j<n;j++){
            if(isConnected[i][j] == 1){
                adjList[i].push_back(j);
            }
        }
    }

    // then count the number of connected comp 
    // since it is not fully connected and we can have more than one comp

    int count = 0; 

    for(int i = 0; i<n;i++){
        if(vis[i] == -1){
            dfs(adjList, vis, n, i);
            count++;
        }
    }

    return count;
}