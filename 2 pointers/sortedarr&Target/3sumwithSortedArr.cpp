// link https://leetcode.com/problems/3sum/description/

// Problem : Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k,
// nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.
// Example 1:
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Example 2:
// Input: nums = []
// Output: []
// Example 3:
// Input: nums = [0]
// Output: []

// time : O(n^2) , Space : O(n)

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

vector<vector<int>>triplets;
set<vector<int>>tripletsSet;

int sum = 0;

for(int i = 0; i<n-2; i++) {
    int target = 0 - nums[i];
    int j = i+1;
    int k = n-1;
    vector<int>vec;

    while(j < k) {
        if(nums[j] + nums[k] == target){
            vec.push_back(nums[i]);
            vec.push_back(nums[j]);
            vec.push_back(nums[k]);
            tripletsSet.insert(vec);
            vec.clear();
            j++;
            k--;
        }else if(nums[j] + nums[k] < target) {
            j++;
        } else {
            k--;
        }
    }
}

for(auto elem : tripletsSet) {
    triplets.push_back(elem);
}
return triplets;
}
