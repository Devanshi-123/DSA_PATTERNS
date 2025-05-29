// https://leetcode.com/problems/permutation-in-string/description/

bool checkInclusion(string s1, string s2) {
    int n = s2.size();
    int m = s1.size();

    unordered_map<char,int>freq;
    unordered_map<char,int>targetFreq;

    for(char ch : s1){
        targetFreq[ch]++;
    }

    int i = 0;
    int j = 0;

    while(j < n){
        freq[s2[j]]++;

        // invalid 
        while(j-i+1 > m && i<=j){
            if(freq[s2[i]] > 1){
                freq[s2[i]]--;
            }else {
                freq.erase(s2[i]);
            }
            i++;
        }

        // valid 
        if(j-i+1 == m){
            if(freq == targetFreq){
                return true;
            }
        }

        j++;
    }

    return false;       
    }