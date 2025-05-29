// https://leetcode.com/problems/course-schedule-ii/

// Time : O(n+m)
// Space : O(n+m)
// where n is the number of courses and m is the number of prerequisites

void bfs(queue<int> &q,vector<int> &vis,int numCourses,vector<vector<int>> &adjList,vector<int> &path, vector<int> &indegree){
    while(!q.empty()){
        int curr = q.front();
        path.push_back(curr);

        q.pop();

        for(auto neigh : adjList[curr]){
            if(vis[neigh] == -1){
                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    q.push(neigh);
                    vis[neigh] = 1;
                }
            }
        }
    }
}
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>>adjList(numCourses+1);
    vector<int>indegree(numCourses+1, 0);

    for(auto edge : prerequisites){
        int u = edge[1];
        int v = edge[0];

        adjList[u].push_back(v);
        indegree[v]++;
    }

    // multisource bfs 
    queue<int>q;

    vector<int>vis(numCourses+1, -1);

    for(int i = 0; i<numCourses; i++){
        if(indegree[i] == 0){
            q.push(i);
            vis[i] = 1;
        }
    }

    vector<int>path;

    bfs(q, vis, numCourses, adjList, path, indegree);

    for(int i = 0; i<numCourses; i++){
        vector<int>ans;
        if(indegree[i] != 0){
            return ans;
        }
    }

    return path;
}