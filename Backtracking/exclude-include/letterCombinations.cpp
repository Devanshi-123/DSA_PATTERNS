// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

// Time : O(2^(n*3)) -> O(3^n)
// Space : O(n)

class Solution {
public:
    void solve(int i, int n, string &digits, string &path, vector<string> &ans, unordered_map<char, string> &mapping){
        if(path.size() == n){
            ans.push_back(path);
            return;
        }

        if(i >= n){
            return;
        }

        // explore choices 
        for(auto elem : mapping[digits[i]]){
            path += elem;
            solve(i+1, n, digits, path, ans, mapping);
            path.pop_back();
            solve(i+1, n, digits, path, ans, mapping);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        int n = digits.size();

        if(n == 0){
            return ans;
        }

        string path = "";

        unordered_map<char, string>mappings;
        mappings['2'] = "abc";
        mappings['3'] = "def";
        mappings['4'] = "ghi";
        mappings['5'] = "jkl";
        mappings['6'] = "mno";
        mappings['7'] = "pqrs";
        mappings['8'] = "tuv";
        mappings['9'] = "wxyz";

        solve(0, n, digits, path, ans, mappings);

        return ans;
    }
};