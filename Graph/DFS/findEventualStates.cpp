// https://leetcode.com/problems/find-eventual-safe-states/submissions/1263804971/

bool dfs(int source, vector<int>&isVis,vector<int>&isPathVis, vector<int>&isSafe ,int nodes,vector<vector<int>>&graph){
    // mark it visited 
    isVis[source] = 1;
    isPathVis[source] = 1;
    isSafe[source] = 0;
   
    for(auto adjNode : graph[source]){
        if(isVis[adjNode] == 0){
            if(dfs(adjNode,isVis,isPathVis,isSafe,nodes,graph) == true){
                isSafe[adjNode] = 0;
                return true;
            }
        }
        else if(isPathVis[adjNode] != 0){
            // cycle detected
            isSafe[adjNode] = 0;
            return true;
        }
    }
     isPathVis[source] = 0;
     isSafe[source] = 1;
     return false;
}
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    // directed graph ==> n nodes 
    // 0 based indexing 
    // adj list -> graph 
    int nodes = graph.size();

    // terminal node graph[i] = empty no adj nodes
    // safe node if all adj nodes are terminal or safe 
    // three array 
    vector<int>isVis(nodes,0);
    vector<int>isPathVis(nodes,0);
    vector<int>isSafe(nodes,0);
    vector<int>ans;
    for(int i=0;i<nodes;i++){
        if(isVis[i] == 0){
            dfs(i,isVis,isPathVis,isSafe,nodes,graph);
        }
    }
    for(int i=0;i<nodes;i++){
        if(isSafe[i] == 1){
            ans.push_back(i);
        }
    }
    return ans;
}