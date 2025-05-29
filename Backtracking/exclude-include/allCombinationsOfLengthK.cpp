// https://leetcode.com/problems/combinations/

// Time : O(2^n)
// Space : O(k)

void helper(vector<vector<int>>&ans, vector<int>op, int n, int k, int i){
    // prune i.e if not possible then return 
    if(op.size() + (n-i+1) < k){
        return;
    }
   
    // cond case 
    if(op.size() == k){
        ans.push_back(op);
        return;
    }

     // base case 
    if(i > n){
        return;
    }

    // explore choices 
    op.push_back(i);
    helper(ans, op, n, k, i+1);
    op.pop_back();
    helper(ans, op, n, k, i+1);
}
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>>ans;
    vector<int>op;

    helper(ans, op, n, k, 1);

    return ans;
}