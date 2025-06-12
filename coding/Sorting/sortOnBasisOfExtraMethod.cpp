// https://leetcode.com/problems/maximum-star-sum-of-a-graph/

int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>>adjList(n);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        for(int i = 0; i<n;i++){
            sort(adjList[i].begin(), adjList[i].end(), [&vals](int a, int b){
                if(vals[a] == vals[b]){
                    return a<b;
                }

                return vals[a] > vals[b];
            });
        }

        int maxSum = INT_MIN;

        for(int i = 0; i<n;i++){
            int m = min((int)k,(int) adjList[i].size());
            int maxNeighSum = vals[i];
            for(int j = 0; j<m;j++){
                if((maxNeighSum + vals[adjList[i][j]]) < maxNeighSum){
                    break;
                }
                maxNeighSum += vals[adjList[i][j]];
            }
            maxSum = max(maxSum, maxNeighSum);
        }

        return maxSum;
    }