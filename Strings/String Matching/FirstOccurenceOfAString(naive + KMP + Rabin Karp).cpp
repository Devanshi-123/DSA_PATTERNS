// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

// Time Complexity: O(n * m) in the worst case
// Where:

// n = length of str (main string)

// m = length of stub (substring)
// Space Complexity: O(1)

class Solution {
    public:
        int strStr(string haystack, string needle) {
            if(needle == ""){
                return 0;
            }
    
            if(haystack.find(needle) != string::npos){
                return haystack.find(needle);
            }
    
            return -1;
        }
    };

// Naive Approach
// Time Complexity: O(n * m) in the worst case
// Space Complexity: O(1)

int strStr(string haystack, string needle) {
    int n = haystack.size();
    int m = needle.size();

    int i,j,k;
    i = j = k = 0;

    while(i < n && j < m){
        if(haystack[i] == needle[j]){
            i++;
            j++;
        }else{
            j = 0;
            i = k+1;
            k++;
        }
    }

    if(j == m){
        return k;
    }

    return -1;
}

// KMP Algo 
// Time Complexity: O(n + m)
// Space Complexity: O(m)

class Solution {
    public:
    int kmp(vector<int> &lps, string text, string pattern,int n,int m){
            int i = 0,j = 0;
            while(i < n){
                if(text[i] == pattern[j]){
                    j++;
                    i++;
                    if(j == m){
                        return i-m;
                    }
                }else {
                    if(j != 0){
                        j = lps[j-1];
                    }else {
                        i++;
                    }
                }
            }
            return -1;
        }
        vector<int> constructLPS(string pattern, int m){
            vector<int>lps(m, 0);
            // longest prefix which is equal to the suffix except the string itself 
    
            int i = 1;
            int prevLPS = 0;
    
            while(i < m){
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
        int strStr(string haystack, string needle) {
            int n = haystack.size();
            int m = needle.size();
    
            if(m == 0){
                return 0;
            }
    
            vector<int>lps = constructLPS(needle, m);
            return kmp(lps, haystack, needle, n, m);
        }
    };