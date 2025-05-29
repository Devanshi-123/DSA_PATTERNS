// https://leetcode.com/problems/keys-and-rooms/submissions/1629207892/

void dfs(vector<vector<int>> &rooms, int n, vector<int> &vis, int src){
    vis[src] = 1;


    // explore neigh 
    for(auto neigh : rooms[src]){
        if(vis[neigh] == -1){
            dfs(rooms, n, vis, neigh);
        }
    }
}
bool canVisitAllRooms(vector<vector<int>>& rooms) {
    // 0 to n-1 
    // src : 0
    int n = rooms.size();
    vector<int>vis(n+1, -1);

    dfs(rooms, n, vis, 0);

    for(int i = 0; i<n;i++){
        if(vis[i] == -1){
            return false;
        }
    }

    return true;

}