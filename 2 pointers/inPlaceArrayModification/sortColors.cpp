// https://leetcode.com/problems/sort-colors/

// O(n)
// O(1)

void sortColors(vector<int>& nums) {
    int n = nums.size();
    int start = 0;
    int mid = 0;
    int end = n-1;

    int i = 0;

    while(i < n && start <= end && mid <= end){
        if(nums[i] == 0){
            swap(nums[start++], nums[i++]);
            mid++;
        }else if(nums[i] == 1){
            swap(nums[mid++], nums[i++]);
        }else {
            swap(nums[end--], nums[i]);
        }
    }
}