// https://leetcode.com/problems/count-the-number-of-complete-components/?envType=company&envId=google&favoriteSlug=google-three-months

// Time : O(n^2)
// Space : O(n)
// Approach : DFS

class Solution {
public:
void dfs(int src , vector<vector<int>>&adjList, int n, vector<int> &vis, vector<int>&trav){
    vis[src] = 1;
    trav.push_back(src);
    

    cout << "src" << src << endl;

    // explore neigh
    cout << "size" << adjList[src].size() << endl;

    for(auto neigh : adjList[src]){
        cout << "neigh" << neigh << endl;
        if(vis[neigh] == -1){
            dfs(neigh, adjList, n, vis, trav);
        }
    }
    return;
}
int countCompleteComponents(int n, vector<vector<int>>& edges) {
    // undirected graph 
    // n vertices : 0 based indexing : 0 to n-1 

    int numOfEdges = edges.size();
    // adjlist from edges 
    vector<vector<int>>adjList(n+1);
    int count = 0;
    int completeCount = 0;

    for(int i = 0; i< numOfEdges; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i = 0; i< n; i++){
        sort(adjList[i].begin(), adjList[i].end());
    }

    vector<int>vis(n+1, -1);
    for(int i = 0; i<n;i++){
        if(vis[i] == -1){
            cout << "i" << i << endl;
            count++;
            vector<int>trv;
            bool flag = true;
            dfs(i, adjList, n, vis, trv);
            for(int j = 0; j< trv.size()-1;j++){
                for(int k = j+1; k<trv.size(); k++){
                    if(binary_search(adjList[trv[j]].begin(), adjList[trv[j]].end(), trv[k]) == false){
                        flag = false;
                    }
                }
            }
            if(flag == true){
                completeCount++;
            }
        }
    }

    return completeCount;
}
};

// Approach 2 : DFS 

// That in a complete graph the number of edges is equal to n*(n-1)/2
// Time : O(n+m)

void dfs(int src , vector<vector<int>>&adjList, int n, vector<int> &vis, pair<int, int>&comp){
    vis[src] = 1;
    // the number of vertices
    comp.first++;
    // number of edges for this vertex
    comp.second += adjList[src].size();
    

    cout << "src" << src << endl;

    // explore neigh
    cout << "size" << adjList[src].size() << endl;

    for(auto neigh : adjList[src]){
        cout << "neigh" << neigh << endl;
        if(vis[neigh] == -1){
            dfs(neigh, adjList, n, vis, comp);
        }
    }
    return;
}
int countCompleteComponents(int n, vector<vector<int>>& edges) {
    // undirected graph 
    // n vertices : 0 based indexing : 0 to n-1 

    int numOfEdges = edges.size();
    // adjlist from edges 
    vector<vector<int>>adjList(n+1);
    int count = 0;
    int completeCount = 0;

    for(int i = 0; i< numOfEdges; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i = 0; i< n; i++){
        sort(adjList[i].begin(), adjList[i].end());
    }

    vector<int>vis(n+1, -1);
    for(int i = 0; i<n;i++){
        if(vis[i] == -1){
            // this will store the number of vertices and edges in the current connected comp 
            pair<int,int>comp = {0,0};
            dfs(i, adjList, n, vis, comp);
            
            if(comp.second == (comp.first*(comp.first-1))){
                completeCount++;
            }
        }
    }

    return completeCount;
}