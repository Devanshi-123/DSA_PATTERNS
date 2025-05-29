// https://leetcode.com/problems/running-sum-of-1d-array/

// time : O(n)
// space : O(n)

vector<int> runningSum(vector<int>& nums) {
    int n = nums.size();

    vector<int>runningSum(n, 0);
    runningSum[0] = nums[0];

    for(int i = 1; i< n;i++){
        runningSum[i] = nums[i] + runningSum[i-1];
    }

    return runningSum;
}