// https://leetcode.com/problems/binary-subarrays-with-sum/description/

// Time : O(n)
// Space : O(n) 

int numSubarraysWithSum(vector<int>& nums, int goal) {
    // binary arr 
    // no neg number : 0 and 1

    // goal 

    // count of subarrays with sum equal to goal 

    int n = nums.size();

    unordered_map<int,int>idxMap;
    idxMap[0] = 1;
    int prefixSum = 0;
    int count = 0;

    for(int i = 0; i<n;i++){
        prefixSum += nums[i];
        int elem = prefixSum - goal;
        if(idxMap.find(elem) != idxMap.end()){
            count += idxMap[elem];
        }
        if(idxMap.find(prefixSum) != idxMap.end()){
            idxMap[prefixSum]++;
        }else {
            idxMap[prefixSum] = 1;
        }
    }

    return count;
}