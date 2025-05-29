// catalan number is a seq uence of natural numbers that occurs in various counting problems, often involving recursive structures. 
// The nth Catalan number can be expressed directly in terms of binomial coefficients by the formula:
// C(n) = (2n)! / ((n + 1)! * n!)
// just like fibonacci numbers, we can use dynamic programming to calculate the nth catalan number.

// generally used in recursively defined problems like:

// 3.
// 4. number of ways to parenthesize n+1 factors
// 5. number of ways to arrange n pairs of parentheses
// 6. number of ways to connect n points in a plane with non-intersecting chords
// 7. number of ways to form a full binary tree with n internal nodes
// 9. number of ways to partition a set of n elements into k non-empty subsets



// it is summation is C(n) = C(0) * C(n-1) + C(1) * C(n-2) + ... + C(n-1) * C(0)
// C(n) = C(i) * C(n-i-1) for i = 0 to n-1
// C0 = 1
// C1 = 1
// C2 = C0 * C1 + C1 * C0 = 1 * 1 + 1 * 1 = 2

// https://leetcode.com/problems/unique-binary-search-trees/

// brute force approach

// 1. generate all possible trees and count them
// 2. generate all possible trees and check if they are unique
// 3. generate all possible trees and check if they are unique using a set
// 4. generate all possible trees and check if they are unique using a map

// tabluar approach

 void helper(int i, int n, vector<int> &dp){
        // base case 
       dp[0] = 1;
       dp[1] = 1;
        
        for(int i = 2; i<=n;i++){
            for(int j = 0; j<i;j++){
                dp[i] += dp[j]*dp[i-j-1];
            }
        }

    }
    int numTrees(int n) {
        // as if there is no node or 1 node only 1 tree is possible 
        if(n < 2){
            return 1;
        }

        vector<int>dp(n+1, 0);
        helper(0, n, dp);

        return dp[n];
    }