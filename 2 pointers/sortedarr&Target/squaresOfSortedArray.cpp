// https://leetcode.com/problems/squares-of-a-sorted-array/

// Time : O(n)
// Space : O(n)

vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int>ans(n, 0);
    int left = 0;
    int right = n-1;
    int index = n-1;

    while(left <= right){
        if(abs(nums[left]) > abs(nums[right])){
            ans[index] = nums[left] * nums[left];
            left++;
        }else{
            ans[index] = nums[right] * nums[right];
            right--;
        }
        index--;
    }

    return ans;
}
