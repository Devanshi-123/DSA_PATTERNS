// Course schedule : https://leetcode.com/problems/course-schedule/description/

// Approach 1 : deletct cycle in a direct cycle 
// DFS 

bool dfs(vector<int> &vis,vector<int> &pathVis,vector<int> &parent, vector<vector<int>> &adjList,int numCourses, int src){
    cout << "src" << endl;
    vis[src] = 1;
    pathVis[src] = 1;

    // explore neigh 
    for(auto neigh : adjList[src]){
        if(vis[neigh] == 1 && pathVis[neigh] == 1){
            return false;
        }else if(vis[neigh] == -1) {
            parent[neigh] = src;
            if(dfs(vis, pathVis, parent, adjList, numCourses, neigh) == false){
                return false;
            }
        }
    }

    pathVis[src] = -1;
    return true;
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // since topo sort is only possible in dag 

    // of there is a cycle or not 

    // finding cycle in a directed cycle 
    vector<vector<int>>adjList(numCourses+1);
    vector<int>vis(numCourses+1, -1);
    vector<int>pathvis(numCourses+1, -1);
    vector<int>parent(numCourses+1, -1);

    for(auto edge: prerequisites){
        adjList[edge[1]].push_back(edge[0]);
    }

    for(int i = 0; i < numCourses; i++){
        if(vis[i] == -1){
            if(dfs(vis, pathvis, parent, adjList, numCourses, i) == false){
                return false;
            }
        }
    }

    return true;
}


// topo sort

class Solution {
    public:
        void bfs(vector<int>&vis, vector<int>&inDegree, vector<vector<int>>&adjList, int n, queue<int>q){
            while(!q.empty()){
                int node = q.front();
    
                q.pop();
    
                // explore neigh 
                for(auto neigh : adjList[node]){
                    if(vis[neigh] == -1 && inDegree[neigh] != 0){
                        inDegree[neigh]--;
                        if(inDegree[neigh] == 0){
                            vis[neigh] = 1;
                            q.push(neigh);
                        }
                    }
                }
            }
        }
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            // identify : prerequisite
    
            // detect cycle so if linear ordering is possible and we are able to form a topo sort order then we can finish -> DAG 
    
            // if we need to identify : DAG -> if we are able to perform topo sort then DAG 
    
            // kahn's algo 
    
            // step 1 : create adjList from prereq 
            vector<vector<int>>adjList(numCourses+1);
            vector<int>inDegree(numCourses+1, 0);
            vector<int>vis(numCourses+1, -1);
    
            int n = prerequisites.size();
    
            // step 2 : populate adjList and indegree 
            for(int i = 0; i<n; i++){
                int u = prerequisites[i][0];
                int v = prerequisites[i][1];
    
                inDegree[v]++;
                adjList[u].push_back(v);
            }
    
            // multisource bfs 
            // queue 
            // source : all the unvisited nodes with indegree 0
    
            queue<int>q;
            for(int i = 0; i<numCourses; i++){
                if(vis[i] == -1 && inDegree[i] == 0){
                    vis[i] = 1;
                    q.push(i);
                }
            }
    
            bfs(vis, inDegree, adjList, numCourses , q);
    
            for(int i = 0; i<numCourses; i++){
                // there is a cycle and it is not a DAG so linear ordering is not possible 
                if(inDegree[i] != 0){
                    return false;
                }
            }
    
            return true;
        }
    };