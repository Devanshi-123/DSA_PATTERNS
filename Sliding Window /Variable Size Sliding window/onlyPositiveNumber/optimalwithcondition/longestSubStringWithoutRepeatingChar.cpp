// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int n = s.size();
            if(n <= 1){
                return n;
            }
    
            int i =0;
            int j = 0;
    
            int maxlen = 0;
            unordered_map<char,int>freq;
    
            while(j < n){
                freq[s[j]]++;
    
                // invalid  
                while(freq.size() < j-i+1 && i<=j){
                    if(freq[s[i]] > 1){
                        freq[s[i]]--;
                    }else {
                        freq.erase(s[i]);
                    }
                    i++;
                }
    
                 // valid 
                if(freq.size() == j-i+1){
                    maxlen = max(maxlen, j-i+1);
                }
    
                j++; 
    
            }
    
            return maxlen;
        }
    };