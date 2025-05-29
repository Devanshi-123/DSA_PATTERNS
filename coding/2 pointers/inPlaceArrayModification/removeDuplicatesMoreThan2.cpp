// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

// // // Time : O(n)
// // // Space : O(1)

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int currNum = -1;
    int currCount = 0;

    int idxToPlace = 0;

    int i = 0;

    while(i < n){
        if(nums[i] != currNum){
            currNum = nums[i];
            currCount = 1;
        } else {
            currCount++;
        }
        if(currCount <= 2){
            nums[idxToPlace] = nums[i];
            idxToPlace++;
        } 
        i++;
    }

    return idxToPlace;
}