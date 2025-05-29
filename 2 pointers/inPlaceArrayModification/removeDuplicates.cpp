// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// // Time : O(n^2)
// // Space : O(1)

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();

    int count = n;
    int i = 1;

    while(i < nums.size()){
        if(nums[i] == nums[i-1]){
            count--;
            nums.erase(nums.begin()+i);
        }else {
            i++;
        }
    }

    return count;
}