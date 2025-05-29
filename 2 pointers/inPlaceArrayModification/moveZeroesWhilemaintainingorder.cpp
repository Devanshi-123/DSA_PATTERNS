// https://leetcode.com/problems/move-zeroes/description/

void moveZeroes(vector<int>& nums) {
    // O(n) time 
    // O(1) space 

    int countZeroes = 0;

    int n = nums.size();

    for(int i = 0; i<n;i++){
        if(nums[i] == 0){
            countZeroes++;
        }
    }

    int i = 0;
    int j = 0;
    while(j < n){
        if(nums[j] != 0){
            nums[i] = nums[j];
            i++;
            j++;
        }else {
            j++;
        }
    }

    while(i < n){
        nums[i] = 0;
        i++;
    }
}