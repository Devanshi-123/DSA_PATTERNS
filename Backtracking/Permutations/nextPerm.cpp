// https://leetcode.com/problems/next-permutation/

 void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        // since we want lexopgraphically greater 
        // we will traverse from right to left and as soon as we find arr[i] < arr[i+1] we can swap this i will a bigger number 
        // now since we want next only so we would like to swap it with the rightmost greater elem

        int i = n-2;

        while(i >= 0 && nums[i] >= nums[i+1]){
            i--;
        }

        if(i >= 0){
            // rightmost greater elem 
            int j = n-1;
            while(j > i){
                if(nums[j] > nums[i]){
                    swap(nums[i], nums[j]);
                    break;
                }
                j--;
            }
        }

        reverse(nums.begin()+i+1, nums.end());
        return;
    }