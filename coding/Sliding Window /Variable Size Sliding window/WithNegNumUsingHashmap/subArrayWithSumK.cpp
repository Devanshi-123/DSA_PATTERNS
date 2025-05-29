// https://leetcode.com/problems/subarray-sum-equals-k/description/

// Time : O(n)
// Space : O(n) + O(n) = O(n)

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    if(n == 1){
        if(nums[0] == k){
            return 1;
        }else {
            return 0;
        }
    }

    int count = 0;

    unordered_map<int, int>prefixSumMap;

    prefixSumMap[0] = 1;
    int sum = 0;

    for(int i = 0; i< n;i++){
        sum += nums[i];

        if(prefixSumMap.find(sum-k) != prefixSumMap.end()){
            count += prefixSumMap[sum-k];
        }
        if(prefixSumMap.find(sum) != prefixSumMap.end()){
            prefixSumMap[sum]++;
        }else {
            prefixSumMap[sum] = 1;
        }
    }

    return count;
}

