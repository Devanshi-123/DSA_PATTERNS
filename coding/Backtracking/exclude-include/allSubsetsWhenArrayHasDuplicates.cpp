// https://leetcode.com/problems/subsets-ii/description/


void solve(int i, int n, vector<int> &nums, vector<int> &path, set<vector<int>> &sub){
        if(i >= n){
            sub.insert(path);
            return;
        }

        path.push_back(nums[i]);
        solve(i+1, n, nums, path, sub);
        path.pop_back();
        solve(i+1, n, nums, path, sub);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       set<vector<int>>sub;
        vector<vector<int>>ans;

        vector<int>path;

        sort(nums.begin(), nums.end());

        int n = nums.size();

        solve(0, n, nums, path, sub);

        for(auto elem : sub){
            ans.push_back(elem);
        }

        return ans;

    }