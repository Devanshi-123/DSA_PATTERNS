// https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    bool isPalindrome(string &str, int i, int j){
        int n = str.size();

        while(i <= j){
            if(str[i] != str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(string str, int idx, int n, vector<vector<string>> &ans, vector<string>op){
        // base case 
        if(idx >= n){
            ans.push_back(op);
            return;
        }

        // explore all valid choices 
        // as we can put bracket anywhere from the starting index till end 
        for(int i = idx; i<n;i++){
            if(isPalindrome(str, idx, i)){
                op.push_back(str.substr(idx, i-idx+1));
                solve(str, i+1, n, ans, op);
                op.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        int n = s.size();

        if(n == 1){
            vector<string>temp;
            temp.push_back(s);
            ans.push_back(temp);
            return ans;
        }

        // since we have to return all possible partioned 
        // less time complexity 
        // backtracking 
        vector<string>op;
        solve(s, 0, n, ans, op);
        return ans;
    }
};