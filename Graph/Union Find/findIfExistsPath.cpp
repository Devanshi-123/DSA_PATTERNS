// https://leetcode.com/problems/path-existence-queries-in-a-graph-i

// Time Complexity : O(n^2 + q) or O(n+m+q) where m is the number of edges
// n : number of nodes
// q : number of queries
// Space Complexity : O(n + q)

class Solution {
    private:
        class DisjointSet{
            public: 
    
            vector<int>size;
            vector<int>parent;
    
            DisjointSet(int n){
                size.resize(n);
                parent.resize(n);
                for(int i = 0; i<n;i++){
                    size[i] = 1;
                    parent[i] = i;
                }
            }
    
            int findParent(int node){
                // base case 
                if(parent[node] == node){
                    return node;
                }
    
                // path compression
                return parent[node] = findParent(parent[node]);
            }
    
            bool isSameComponent(int u, int v){
                return findParent(u) == findParent(v);
            }
    
            void unionBySize(int u, int v){
                int pu = findParent(u);
                int pv = findParent(v);
    
                if(size[pu] >= size[pv]){
                    parent[pv] = pu;
                    size[pu] += size[pv];
                }else {
                    parent[pu] = pv;
                    size[pv] += size[pu];
                }
            }
        };
        void populatePath(vector<int> &nums, int n, int maxDiff, vector<vector<int>> &edges){
            // vssw 
            int i = 0;
            int j = 0;
    
            while(j< n){
    
                // invalid 
                while((abs(nums[i]-nums[j]) > maxDiff) && i <= j){
                    i++;
                }
    
                if(abs(nums[i]-nums[j]) <= maxDiff){
                    if(i == j){
                        edges.push_back({i,j});
                    }else {
                        edges.push_back({i,j});
                        edges.push_back({j,i});
                    }
                }
    
                j++;
            }
        }
        vector<bool> unionFind(vector<vector<int>> &edges, int n, vector<vector<int>> &queries){
            DisjointSet ds(n);
    
            vector<bool>pathExists;
    
            for(auto edge : edges){
                int u = edge[0];
                int v = edge[1];
    
                if(!ds.isSameComponent(u, v)){
                    ds.unionBySize(u, v);
                }
            }
    
            for(auto query : queries){
                int u  = query[0];
                int v = query[1];
    
                if(!ds.isSameComponent(u, v)){
                    pathExists.push_back(false);
                }else {
                    pathExists.push_back(true);
                }
            }
    
            return pathExists;
        }
    public:
        vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
            // n : nodes -> 0 to n-1
            // nums -> length : n -> increasing order : nums[i] >= 0
            // maxDiff
            // undirected edge btq i and j if (abs(nums[i] - nums[j]) <= maxDiff)
            // query : true or false if there exist a path 
    
    
            vector<vector<int>>edges;
    
            populatePath(nums, n, maxDiff, edges);
    
            return unionFind(edges, n, queries);
        }
    };