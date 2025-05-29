// https://leetcode.com/problems/russian-doll-envelopes/

// Time : O(n^2)
// Space : O(n)

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();

        if(n < 1){
            return n;
        }

        // it means there 0 which are smaller 
        vector<int>dp(n, 1);
        sort(envelopes.begin(), envelopes.end());

        for(int i = 0; i<n;i++){
            for(int j = 0; j<i;j++){
                if((envelopes[i][0] > envelopes[j][0]) && (envelopes[i][1] > envelopes[j][1]) && dp[i] < dp[j]+1 ){
                    dp[i] = dp[j]+1;
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

// Approach 2: Binary Search + DP
// Time : O(nlogn)
// Space : O(n)


