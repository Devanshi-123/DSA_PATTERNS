// https://leetcode.com/problems/permutations/description/

 void solve(int i, int n, set<vector<int>> &s, vector<int> &nums){
        // base case 
        if(i >= n){
            s.insert(nums);
            return;
        }

        // explore valid cond 
        for(int j = 0; j<n;j++){
            // choice to swap 
            swap(nums[i], nums[j]);
            solve(i+1, n, s, nums);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // nums 
        // unique 
        // all possible : backtracking 
        // nums : [1, 2, 3] 
        // n : 3 -> i : 0 , 1, 2

        int n = nums.size();
        set<vector<int>>s;
        vector<vector<int>>ans;

        solve(0, n, s, nums);

        for(auto elem : s){
            ans.push_back(elem);
        }

        return ans;
    }