// https://leetcode.com/problems/minimum-height-trees/

void bfs(queue<int> &q,vector<vector<int>> &adjlist,vector<int> &degree, int &rem){
    while(rem > 2 && !q.empty()){
        int sz = q.size();
        // we eremobe the leaf nodes from the all the nodes 
        rem -= sz;
       
        for(int i = 0; i<sz;i++){
            int curr = q.front();
            q.pop();
            for(auto neigh : adjlist[curr]){
                degree[neigh]--;
                if(degree[neigh] == 1){
                    q.push(neigh);
                }
            }
        }
    }
}
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    vector<int>ans;
    if(n < 3){
        for(int i = 0; i<n;i++){
            ans.push_back(i);
        }
        return ans;
    }

    vector<vector<int>>adjlist(n);
    vector<int>degree(n, 0);
    queue<int>q;

    // [[0,1],[0,2],[0,3],[3,4],[4,5]]
    // 1, 1, 1, 2, 1, 1
    //  5 0 

    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);

        degree[u]++;
        degree[v]++;

    }

    for(int i = 0; i<n;i++){
        if(degree[i] == 1){
            q.push(i);
        }
    }

    int remaining = n;

    bfs(q, adjlist, degree, remaining);

    while(!q.empty()){
        ans.push_back(q.front());
        q.pop();
    }

    return ans;
}