// https://leetcode.com/problems/find-the-duplicate-number/

// Time : O(n)
// Space : O(1)

int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    // First phase: find intersection point
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Second phase: find entrance to cycle
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}