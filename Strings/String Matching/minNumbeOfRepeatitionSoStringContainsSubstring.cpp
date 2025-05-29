// https://leetcode.com/problems/repeated-string-match/


// Time Complexity: O(m*(n + m)) in the worst case
// Space Complexity: O(1)
// Where:
// m = length of b (sub string)
// n = length of a (main string)

class Solution {
    public:
        int repeatedStringMatch(string a, string b) {
            int count = 1;
            if(a.find(b) != string::npos){
                return 1;
            }
            string orig = a;
    
            while(a.size() <= b.size()+orig.size()){
                a += orig;
                // abcabcabc
                count++;
                if(a.find(b) != string::npos){
                    cout << "a" << a << endl;
                    return count;
                }
            }
            return -1;
        }
    };

// Optimal Solution KMP Algorithm

// Time Complexity: O(n + m)
// Space Complexity: O(m)

// It is used for pattern matching i.e. if a text is there find if a pattern exists in the text or not if yes find its index 

