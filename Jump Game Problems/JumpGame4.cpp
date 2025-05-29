// https://leetcode.com/problems/jump-game-iv/

// // BFS + visited
// // O(n)
// // O(n)

class Solution {
    private:
        int bfs(vector<int>&arr, int n, vector<int> &vis, queue<pair<int,int>>&minHp,  unordered_map<int, vector<int>> &mp){
            while(!minHp.empty()){
                int currCount = minHp.front().first;
                int idx = minHp.front().second;
    
                if(idx >= n-1){
                    return currCount;
                }
    
                minHp.pop();
    
                // explore neigh
                int left = idx-1;
                int right = idx+1;
                if(left >= 0 && vis[left] == 0){
                    minHp.push({currCount+1, left});
                    vis[left] = 1;
                }
                if(right < n && vis[right] == 0){
                    minHp.push({currCount+1, right});
                    vis[right] = 1;
                }
                for(auto neigh : mp[arr[idx]]){
                    if(neigh != idx && vis[neigh] == 0){
                        minHp.push({currCount+1, neigh});
                        vis[neigh] = 1;
                    }
                }
                mp.erase(arr[idx]);
            }
            return -1;
        }
    public:
        int minJumps(vector<int>& arr) {
            int n = arr.size();
    
            if(n <= 1){
                return 0;
            }
    
            vector<int>vis(n+1, 0);
            // min heap 
            
            queue<pair<int,int>>minHp;
            minHp.push({0,0});
            vis[0] = 1;
    
            unordered_map<int, vector<int>>mp;
    
            for(int i = 0; i<n;i++){
                mp[arr[i]].push_back(i);
            }
    
            return bfs(arr, n, vis, minHp, mp);
        }
    };