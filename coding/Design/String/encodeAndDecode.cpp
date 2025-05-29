// https://leetcode.com/problems/encode-and-decode-strings/description/\

// Time : O(n*m) : n is the number of strings and m is the average length of the strings
// Space : O(n*m) : n is the number of strings and m is the average length of the strings

class Codec {
    public:
    
        // Encodes a list of strings to a single string.
        string encode(vector<string>& strs) {
            string s = "";
            int n = strs.size();
            for(int i = 0; i<n;i++){
                int len = strs[i].size();
                string length = to_string(len);
                s += length + '#' + strs[i];
            }
            return s;
        }
    
        // Decodes a single string to a list of strings.
        vector<string> decode(string s) {
            vector<string> r;
            int i = 0;
            while (i < s.size())    {
                int at_pos = s.find_first_of('#', i);
                int len = stoi(s.substr(i, at_pos - i));
                i = at_pos + 1;
                r.push_back(s.substr(i, len));
                i += len;
            }
            
            return r;
        }
    };
    
    // Your Codec object will be instantiated and called as such:
    // Codec codec;
    // codec.decode(codec.encode(strs));