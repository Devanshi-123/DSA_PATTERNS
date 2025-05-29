

// https://leetcode.com/problems/generate-parentheses/

// Time : O(2^2*n)
// Space : O(n)

void helper(string str, vector<string>&ans, int totalOpen, int totalClosing){
    // bc 
    if(totalOpen == 0 && totalClosing == 0){
        ans.push_back(str);
        return;
    }

    // explore choices 
    if(totalOpen == 0 && totalClosing > 0){
        str += ')';
        helper(str, ans, totalOpen, totalClosing-1);
    }

    if(totalClosing > totalOpen && totalClosing > 0 && totalOpen > 0){
        str += ')';
        helper(str, ans, totalOpen, totalClosing-1);
        str.pop_back();
        str += '(';
        helper(str, ans, totalOpen-1, totalClosing);
    }else if(totalOpen > 0) {
        str += '(';
        helper(str, ans, totalOpen-1, totalClosing);
    }

}
vector<string> generateParenthesis(int n) {
    // n pair of parenthesis 
    vector<string>ans;

    string str = "";
    int totalOpen = n;
    int totalClose = n;
    helper(str, ans, totalOpen, totalClose);

    return ans;
}