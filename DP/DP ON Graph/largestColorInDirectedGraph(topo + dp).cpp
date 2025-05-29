// https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/
// // Approach 1: Topological Sort + DP
// // Time : O(n + e)
// // Space : O(n + e)
 void bfs(queue<int> &q, vector<int> &indegree, int &maxFreq, vector<vector<int>> &dp, vector<vector<int>> &adjList, string &colors){
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            int colorIdx = colors[curr] - 'a';
            dp[curr][colorIdx]++;

            for(auto neigh : adjList[curr]){
                for(int i = 0; i<26; i++){
                        dp[neigh][i] = max(dp[curr][i], dp[neigh][i]);
                    }
                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    q.push(neigh);
                }
            }

            maxFreq = max(maxFreq, dp[curr][colorIdx]);
        }
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        // hr node ke lie us index tk hr color ki max freq kya ho skti h wo store krenge 
        int n = colors.size();
        vector<vector<int>>adjList(n);
        vector<int>indegree(n, 0);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            indegree[v]++;
        }

        vector<vector<int>>dp(n, vector<int>(26, 0));

        queue<int>q;

        for(int i = 0; i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int maxFreq = 0;

        bfs(q, indegree, maxFreq, dp, adjList, colors);

        for(int i = 0; i<n;i++){
            if(indegree[i] != 0){
                return -1;
            }
        }

        return maxFreq;
    }