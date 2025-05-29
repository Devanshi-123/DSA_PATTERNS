// https://leetcode.com/problems/count-cells-in-overlapping-horizontal-and-vertical-substrings

class Solution {
    private:
        vector<int> kmp(string target, string src, int n, int m, vector<int> &lps){
            int i = 0;
            int j = 0;
            vector<int>idx;
    
            while(i < n){
                if(target[i] == src[j]){
                    i++;
                    j++;
                    if(j == m){
                        idx.push_back(i-m);
                        j = lps[j-1];
                    }
                }else {
                    if(j != 0){
                        j = lps[j-1];
                    }else {
                        i++;
                    }
                }
            }
            return idx;
        }
        vector<int> constructLPS(string pattern,int len){
            vector<int>lps(len, 0);
    
            int prevLPS = 0;
            int i = 1;
            
            while(i<len){
                if(pattern[i] == pattern[prevLPS]){
                    lps[i] = prevLPS+1;
                    prevLPS++;
                    i++;
                }else {
                    if(prevLPS == 0){
                        lps[i] = 0;
                        i++;
                    }else {
                        prevLPS = lps[prevLPS-1];
                    }
                }
            }
    
            return lps;
        }
    public:
        int countCells(vector<vector<char>>& grid, string pattern) {
            // m*n
            // string matching : kmp , rolling hash 
    
            int m = grid.size();
            int n = grid[0].size();
            int len = pattern.size();
            int count = 0;
    
            string hozString = "";
            vector<pair<int,int>>horidx;
            string verString = "";
            vector<pair<int,int>>veridx;
    
            // flatten the grid 
    
            for(int i = 0; i<m;i++){
                for(int j = 0; j<n;j++){
                    hozString += grid[i][j];
                    horidx.push_back({i,j});
                }
            }
            // 9
            // a a c c b b b c a a b a c a a c a a b a
    
            for(int i = 0; i<n;i++){
                for(int j = 0; j<m;j++){
                    verString += grid[j][i];
                    veridx.push_back({j,j});
                }
            }
            // a b a c a a b a a a c b b a b c c a c a 
            // (0,0)(1,0)(2,0)(3,0)(4,0)
            // apply kmp to find the first idx of substring in hoz and ver 
            vector<int>lps = constructLPS(pattern, len);
            vector<int>hozIdx = kmp(hozString, pattern, m*n, len, lps);
            vector<int>verIdx = kmp(verString, pattern, m*n, len, lps);
    
            map<pair<int, int>, int> matchedCells;
            map<pair<int,int>, int>ans;
    
            // Horizontal
            for(int idx : hozIdx){
                if(idx + len <= m * n){
                    for(int k = 0; k < len; k++){
                        int pos = idx + k;
                        int row = pos / n;
                        int col = pos % n;
                        if(matchedCells.find({row, col}) == matchedCells.end()){
                            matchedCells[{row, col}] = 1;
                        }
                        matchedCells[{row, col}]++;
                    }
                }
            }
    
            // Vertical
            for(int idx : verIdx){
                if(idx + len <= m * n){
                    for(int k = 0; k < len; k++){
                        int pos = idx + k;
                        int row = pos % m;
                        int col = pos / m;
                        if(matchedCells.count({row, col})){
                             if(ans.find({row, col}) == ans.end()){
                                ans[{row, col}] = 1;
                            }
                            ans[{row, col}]++;
                        }
                    }
                }
            }
    
                
    
            return ans.size();
    
        }
    };