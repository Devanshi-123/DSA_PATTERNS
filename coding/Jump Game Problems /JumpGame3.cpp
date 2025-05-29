// https://leetcode.com/problems/jump-game-iii/

// DFS + visited 

// O(n) time complexity
// O(n) space complexity

class Solution {
    private: 
        bool helper(vector<int>&arr, int src, vector<int>&vis,int n){
            vis[src] = 1;
    
            if(arr[src] == 0){
                return true;
            }
    
            // explore neighbours 
            if(src + arr[src] < n && vis[src+arr[src]] == 0){
                if(helper(arr, src+arr[src], vis, n)){
                    return true;
                }
            }
            if(src - arr[src] >= 0 && vis[src-arr[src]] == 0){
                if(helper(arr, src-arr[src], vis, n)){
                    return true;
                }
            }
    
            return false;
        }
    public:
        bool canReach(vector<int>& arr, int start) {
            int n = arr.size();
            if(arr[start] == 0){
                return true;
            }
    
            int count = 0;
            for(int i = 0; i<n;i++){
                if(arr[i] == 0){
                    count++;
                }
            }
            if(count == 0){
                return false;
            }
    
            vector<int>vis(n+1, 0);
    
            return helper(arr, start, vis, n);
        }
    };