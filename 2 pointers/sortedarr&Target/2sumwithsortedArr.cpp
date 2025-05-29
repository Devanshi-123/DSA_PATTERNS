// Generally in 2 pointer arr is sorted 
// we take two pointers and then move in the doirection where the chances of finding aswer is more 

// link : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

// Time : O(n) , Space : O(1)
// Approach : 1. Initialize two pointers, left and right, at the beginning and end of the array respectively.
// 2. While left is less than right, calculate the sum of the elements at the two pointers.
// 3. If the sum is equal to the target, return the indices of the two elements.
// 4. If the sum is less than the target, move the left pointer to the right to increase the sum.
// 5. If the sum is greater than the target, move the right pointer to the left to decrease the sum.
// 6. If no solution is found, return an empty vector.

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;        
vector<int> twoSum(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    vector<int> indexes;

    while (left < right) {
        int sum = nums[left] + nums[right];

        if (sum == target) {
            indexes.push_back(left);
            indexes.push_back(right);
            return indexes;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    return indexes; // Return an empty vector if no solution is found
}