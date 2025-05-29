// https://leetcode.com/problems/find-all-anagrams-in-a-string/submissions/1621703894/

// O(n*m)
// O(n)

vector<int> findAnagrams(string s, string p) {
    // fixed size sliding window 
    int n = s.size();
    int m = p.size();

    unordered_map<char,int>freq;
    unordered_map<char,int>targetFreq;
    vector<int>idx;

    for(char ch : p){
        targetFreq[ch]++;
    }

    int i = 0;
    int j = 0;

    while(j < n){
        freq[s[j]]++;

        // invalid 
        while(j-i+1 > m && i<=j){
            if(freq[s[i]] > 1){
                freq[s[i]]--;
            }else {
                freq.erase(s[i]);
            }
            i++;
        }

        // valid 
        if(j-i+1 == m){
            if(freq == targetFreq){
                idx.push_back(i);
            }
        }

        j++;
    }

    return idx;       
}