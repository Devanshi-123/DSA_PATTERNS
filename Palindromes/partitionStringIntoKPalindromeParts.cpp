// https://leetcode.com/problems/palindrome-partitioning-iii/

// Time Complexity : O(n^3*k)
// Space Complexity : O(n*k)

int findCost(string &s, int start, int end){
        int change = 0;
        while(start < end){
            if(s[start] != s[end]){
                change++;
            }
            start++;
            end--;
        }
        return change;
    }
    int solve(string s, int i,int k, vector<vector<int>> &dp){
        int n = s.size();

        if(i >= n){
            if(k == 0){
                return 0;
            }
            return INT_MAX;
        }

        if(k == 0){
            return INT_MAX;
        }

        if(dp[i][k] != -1){
            return dp[i][k];
        }

        int minCost = INT_MAX;

        // for all the substring starting with idx i 
        for(int j = i; j<n;j++){
            // min changes to convert the substring from i to j into a palindrome
            int changeCost = findCost(s, i, j);
            // min steps to split remaining substring from idx j+1 into k-1 parts
            int nextPartition = solve(s, j+1, k-1, dp);
            if(nextPartition != INT_MAX){
                minCost = min(minCost, changeCost + nextPartition);
            }

        }
        return dp[i][k] = minCost;
    }
    int palindromePartition(string s, int k) {
        int n = s.size();
        // min changes to split substring from 0th pos into k parts 
        vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
        return solve(s, 0, k, dp);
    }