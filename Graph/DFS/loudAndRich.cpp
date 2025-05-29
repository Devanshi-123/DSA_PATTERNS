// https://leetcode.com/problems/loud-and-rich/submissions/1643227039/

// Time O(n(n+m))
// Space O(n+m) : n for quiet array and m for adjacency list

 void dfs(int src,vector<vector<int>> &adjList,vector<int> &quiet,int &minQuiteness,int &quiteElem, vector<int> &vis){
        vis[src] = 1;

        if(quiet[src] <= minQuiteness){
            minQuiteness = quiet[src];
            quiteElem = src;
        }

        // explore neigh 
        for(auto neigh : adjList[src]){
            if(vis[neigh] == -1){
                dfs(neigh, adjList, quiet, minQuiteness, quiteElem, vis);
            }
        }
        return;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        // n people : 0 - n-1
        // money -> richer[i] -> [a,b] : a > b 
        // quiteness : quiteness of oth person 
        // directed graph 

        // output 
        // answer[x] = y (y has smallest value in quiet among people richer than x)
        // jitne bhi log x ke equal ya zyada richer h unme se sbse quiet 

        // richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
        // edges : dj list store all the elem richer than curr 
        // 0 : {1, 2}
        // 1 : {2, 5}, {3,4}
        // 2 : 
        // 3 : {4,6},{5, 1}, {6, 7}
        // 4 : 
        // 5
        // 6
        // 7 : {3, 4}

        // dj list from edges 

        int n = quiet.size();

        vector<vector<int>>adjList(n+1);

        for(auto edge : richer){
            int u = edge[1];
            int v = edge[0];

            adjList[u].push_back(v);
        }

        vector<int>answer(n+1, 0);
        for(int i = 0; i<n;i++){
            answer[i] = i;
        }

        int minQuiteness = INT_MAX;
        int quiteElem = -1;

        for(int i = 0; i<n;i++){
            vector<int>vis(n+1, -1);
            dfs(i, adjList, quiet, minQuiteness, quiteElem, vis);
            vis.resize(n+1, -1);
            answer[i] = quiteElem;
            minQuiteness = INT_MAX;
            quiteElem = -1;
        }


        answer.pop_back();

        return answer;

    }