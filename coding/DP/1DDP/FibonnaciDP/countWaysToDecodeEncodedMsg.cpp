// https://leetcode.com/problems/decode-ways/

// Time : Exponential 
// Space : O(n) : recursion stack

int helper(string s, int i, int n){
        
        if(i >= n){
            return 1;
        }

        // base cond 
        if(s[i] == '0'){
            return 0;
        }

        //explore choices 

        int takeOneDigit = helper(s, i+1, n);
        // we will only take digits if it is <= 26
        int takeTwoDigits = 0;

        if(i + 1 < n){
            int currDigit = s[i] - '0';
            int nextDigit = s[i+1] - '0';

            int twoDigit = (currDigit * 10) + nextDigit;

            if(twoDigit <= 26){
                takeTwoDigits = helper(s, i+2, n);
            }
        }

        int result = takeOneDigit + takeTwoDigits;

        return result;
    }
    int numDecodings(string s) {
        int n = s.size();

        if(s[0] == '0'){
            return 0;
        }

        if(n <= 1){
            return n;
        }

        return helper(s, 0,n);
    }

// Approach 2 : Memoization

// Time : O(n)
// Space : O(n) : recursion stack + dp array

int helper(string s, int i, int n, vector<int> &dp){
        
        if(i >= n){
            return 1;
        }

        // base cond 
        if(s[i] == '0'){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        //explore choices 

        int takeOneDigit = helper(s, i+1, n, dp);
        // we will only take digits if it is <= 26
        int takeTwoDigits = 0;

        if(i + 1 < n){
            int currDigit = s[i] - '0';
            int nextDigit = s[i+1] - '0';

            int twoDigit = (currDigit * 10) + nextDigit;

            if(twoDigit <= 26){
                takeTwoDigits = helper(s, i+2, n, dp);
            }
        }

        int result =  takeOneDigit + takeTwoDigits;

        return dp[i] = result;
    }
    int numDecodings(string s) {
        int n = s.size();

        if(s[0] == '0'){
            return 0;
        }

        if(n <= 1){
            return n;
        }

        vector<int>dp(101, -1);

        return helper(s, 0,n, dp);
    }