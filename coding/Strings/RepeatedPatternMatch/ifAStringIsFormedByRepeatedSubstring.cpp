// https://leetcode.com/problems/repeated-substring-pattern/description/

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
    public:
        bool repeatedSubstringPattern(string s) {
            // if a string can be formed by repeating substrings 
            string ss = s + s;
            // remove the first and last character
            string trimmed = ss.substr(1, ss.size()-2);
            // so in the trimmed subtring we have the part of both the concatenated strings 
            if(trimmed.find(s) != string::npos){
                return true;
            }
            return false;
        }
    };