// https://leetcode.com/problems/palindrome-partitioning-ii/

// Space Complexity : O(n^2)
// Time Complexity : O(n^2)

 vector<vector<int>>isPal;
    void isPalindrome(string &s){
        int n = s.size();

        isPal.clear();
        isPal.resize(n, vector<int>(n, 0));

        for(int i = 0; i<n;i++){
            // for odd length 
            int left = i;
            int right = i;
            while(left >= 0 && right < n && s[left] == s[right]){
                isPal[left][right] = 1;
                left--;
                right++;
            }
            // for even length 
            left = i;
            right = i+1;
            while(left >= 0 && right < n && s[left] == s[right]){
                isPal[left][right] = 1;
                left--;
                right++;
            }
        }
    }
    // this helper methd will return the min cutrs needed to partition the string from i to j index
    int solve(string &s,vector<int> &dp){
        int n = s.size();
        // base case : invalid case 
        for(int i = 0; i<n;i++){
             if(isPal[0][i] == 1){
                dp[i] = 0;
            }else {
                int minCuts = INT_MAX;
                for(int j=0; j<i;j++){
                    if(isPal[j+1][i] == 1){
                        minCuts = min(minCuts, dp[j]+1);
                    }
                }
                dp[i] = minCuts;
            }
        }

        return dp[n-1];
    }
    int minCut(string s) {
        // mcm 
        // optimal sub problem 
        int n = s.size();

        if(n <= 1){
            return 0;
        }

        // this dp will store the min cuts req to partition the string into palindrome upto length i
        vector<int>dp(n, INT_MAX);
        isPalindrome(s);

        return solve(s, dp);
    }