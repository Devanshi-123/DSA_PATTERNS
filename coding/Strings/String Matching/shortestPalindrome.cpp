// https://leetcode.com/problems/shortest-palindrome/description/

// Approach 1 : Naive 
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
    public:
        bool isPalindrome(string s, int i, int j){
    
            while(i <= j){
                if(s[i] != s[j]){
                    return false;
                }
                i++;
                j--;
            }
            return true;
        }
        string shortestPalindrome(string s) {
            // cafedadefac
            //  lps 
    
            int n = s.size();
            if(n == 1){
                return s;
            }
    
            int i = 0;
            string org = s;
            int j = n-1;
    
            while(!isPalindrome(s, i, j) && j > 0){
                j--;
            }
    
            string str = "";
            for(int k = n-1; k>j;k--){
                str += s[k];
            }
            str += s;
    
    
            return str;
            
        }
    };

// Approach 2 : Rabin Karp Algorithm

// Time Complexity: O(n)
// Space Complexity: O(n)

// Rabin Karp Algorithm is used for pattern matching. It uses hashing to find any substring in the main string.
// It is used to find the longest prefix which is also a suffix.

