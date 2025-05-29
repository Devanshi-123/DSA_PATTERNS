// https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
public:
int characterReplacement(string s, int k) {
    // we will keep track of the max freq elem all the time 

    int n = s.size();

    int i = 0;
    int j = 0;

    int maxFreq = 0;
    int maxLen = 0;
    unordered_map<char, int>freq;

    while(j < n){
        freq[s[j]]++;

        if(freq[s[j]] > maxFreq){
            maxFreq = freq[s[j]];
        }

        // invalid 
        // still we have more characters than the atmost operations 
        while(j-i+1 - maxFreq > k && i<=j){
            freq[s[i]]--;
            i++;
        }

        // valid 
        if(j-i+1 - maxFreq <= k){
            maxLen = max(maxLen, j-i+1);
        }

        j++;
    }

    return maxLen;
}
};