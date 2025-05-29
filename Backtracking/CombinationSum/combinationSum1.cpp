// https://leetcode.com/problems/combination-sum/

    void solve(vector<int>& candidates,int target,int i, int n, int &sum,vector<int> &path,vector<vector<int>> &sumComb){
        // cc 
        if(sum == target){
            sumComb.push_back(path);
            return;
        }

        if(i >= n){
            return;
        }

        // explore choices 
        if(sum + candidates[i] <= target){
            sum += candidates[i];
            path.push_back(candidates[i]);
            solve(candidates, target,i, n, sum, path, sumComb);
            sum -= candidates[i];
            path.pop_back();
            solve(candidates, target,i+1, n, sum, path, sumComb);
        }

        return;


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // candiddates : unique 
        // target 
        int n = candidates.size();
        vector<vector<int>>sumComb;

        if(n == 1 && candidates[0] != target){
            return sumComb;
        }

        sort(candidates.begin(), candidates.end());

        vector<int>path;
        int sum = 0;

        solve(candidates, target,0, n, sum, path, sumComb);

        return sumComb;
    }