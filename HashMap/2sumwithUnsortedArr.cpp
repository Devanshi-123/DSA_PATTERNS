// link : https://leetcode.com/problems/two-sum/
// Problem : Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.
// Example 1:
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]

// Time : O(n) , Space : O(n)
// Approach : 1. Create a hash map to store the elements and their indices.
// 2. Iterate through the array and for each element, check if the complement (target - current element) exists in the hash map.
// 3. If it exists, return the indices of the current element and the complement.

vector<int> twoSum(vector<int>&nums , int target) {
	int n = nums.size();
	unordered_map<int,int>freqMap;
	vector<int>indexes;

	for(int i = 0; i<n ; i++) {
		freqMap[nums[i]] = i;
	}

	for(int i = 0; i<n;i++) {
		int elemToFind = target - nums[i];
			if(freqMap.find(elemToFind) != freqMap.end() && freqMap[elemToFind] != i){
				indexes.push_back(i);
				indexes.push_back(freqMap[elemToFind]);
                return indexes;
			}
	}

	return indexes;
}