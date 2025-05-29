// https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/

// Time : O(n^2)
// Space : O(n)

 int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        vector<int>lis(n, 1);
        vector<int>lds(n, 1);

        for(int i = 0; i<n;i++){
            for(int j = 0; j<i;j++){
                if(nums[i] > nums[j] && (lis[i] < lis[j] + 1)){
                    lis[i] = lis[j] + 1;
                }
            }
        }

        for(int i = n-1; i>=0;i--){
            for(int j = n-1; j > i; j--){
                if(nums[i] > nums[j] && (lds[i] < lds[j] + 1)){
                    lds[i] = lds[j] + 1;
                }
            }
        }

        vector<int>total(n, 0);

        for(int i = 0; i<n;i++){
            total[i] = lis[i] + lds[i];
        }

        int maxElem = -1;

        for(int i = 1; i<n-1;i++){
            if(total[i] >maxElem && lis[i] >=2 && lds[i] >=2){
                maxElem = total[i];
            }
        }

        int numToRemove = n - maxElem;

        return numToRemove+1;
    }