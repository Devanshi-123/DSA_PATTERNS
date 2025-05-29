// https://leetcode.com/problems/subsets/submissions/1636061574/

// time : 2^n 
void solve(int i, int n, vector<int>&path, vector<vector<int>> &powerSet, vector<int> &nums){
        // base case 
        if(i >= n){
            powerSet.push_back(path);
            return;
        }

        path.push_back(nums[i]);
        solve(i+1, n, path, powerSet, nums);
        path.pop_back();
        solve(i+1, n, path, powerSet, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>powerSet;
        vector<int>path;

        int n = nums.size();

        solve(0, n, path, powerSet, nums);

        return powerSet;
    }