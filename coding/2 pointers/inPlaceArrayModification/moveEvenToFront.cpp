// https://leetcode.com/problems/sort-array-by-parity/submissions/1620453830/

vector<int> sortArrayByParity(vector<int>& nums) {
    int i = 0;
    int j = 0;

    int n = nums.size();

    if(n == 1){
        return nums;
    }

    while(j < n && i < n){
        if(nums[j] % 2 == 0){
            swap(nums[i], nums[j]);
            i++;
        }
        j++;
    }

    return nums;
}