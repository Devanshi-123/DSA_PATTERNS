// https://leetcode.com/problems/sliding-window-maximum/
// fixed size slidig window 

// O(n*k)
// O(n)

vector<int> maxInSubarrays(const vector<int>& nums, int k) {
    int i = 0, j = 0;
    vector<int> result;

    while (j < nums.size()) {
        // When we reach window size k
        if (j - i + 1 == k) {
            int maxVal = *max_element(nums.begin() + i, nums.begin() + j + 1);
            result.push_back(maxVal);
            i++; // Slide the window
        }
        j++;
    }

    return result;
}

// Approach 2 : Sliding window + deque
// O(n)
// O(n)

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> maxInSubarrays(const vector<int>& nums, int k) {
    deque<int> dq; // stores indices
    vector<int> result;

    for (int i = 0; i < nums.size(); ++i) {
        // Remove out-of-window indices
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Remove indices whose corresponding values are less than nums[i] so the maxm elem index of the current window is at the front
        // of the deque
        // This ensures that the deque is always sorted in decreasing order
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        // Add current index
        dq.push_back(i);

        // Append max to result (once we have the first full window)
        if (i >= k - 1)
            result.push_back(nums[dq.front()]);
    }

    return result;
}

int main() {
    vector<int> arr = {1, 3, 1, 2, 0, 5};
    int k = 3;
    vector<int> res = maxInSubarrays(arr, k);

    for (int num : res)
        cout << num << " ";
    return 0;
}
