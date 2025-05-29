// https://leetcode.com/problems/detonate-the-maximum-bombs/

// O(n^2)
// O(n) space

void dfs(vector<int> &vis,vector<vector<int>> &adjList,int numBombs,int src,int &count){
    cout << "src" << src << endl;
    vis[src] = 1;
    count++;

    // explore neigh 
    for(auto neigh : adjList[src]){
        if(vis[neigh] == -1){
            dfs(vis, adjList, numBombs, neigh, count);
        }
    }

    return;
}
int maximumDetonation(vector<vector<int>>& bombs) {
    int numBombs = bombs.size();

    vector<vector<int>>adjList(numBombs+1);

    for(int i = 0; i<numBombs;i++){
        for(int j = 0; j<numBombs; j++){
            if(i!= j){
                int x1 = bombs[i][0];
                int y1 = bombs[i][1];
                int x2 = bombs[j][0];
                int y2 = bombs[j][1];

                long long calRadius = (long long) pow((x2-x1), 2)+(long long)pow((y2-y1), 2);
                int r1 = bombs[i][2];
                int r2 = bombs[j][2];

                if(calRadius <= (long long) r1*r1){
                    adjList[i].push_back(j);
                }
            }
        }
    }

    // vector<int>vis(numBombs, -1);
    int maxCount = 0;
    for(int i = 0; i<numBombs; i++){
        vector<int> vis(numBombs, -1); 
        int count = 0;
        dfs(vis, adjList, numBombs, i, count);
        maxCount = max(maxCount, count);
    }

    return maxCount;
}