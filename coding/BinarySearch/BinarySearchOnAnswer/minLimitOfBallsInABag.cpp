// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/

// Time : O(nlog(maxNum))
// Space : O(1)



bool isValid(int mxAllowedPenalty,vector<int> &nums,int maxOperations){
        long long count = 0;
        for(auto num : nums){
            count += (num-1)/mxAllowedPenalty;
        }

        return count <= maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        // nums : nums[i] -> balls in ith bag 
        // maxOperations

        // atmost ops time can perform two oper : 
        // - split balls into two bags 
        
        // penalty : maxm balls in any bag 
        // min penalty 

        // start = 1, end = 9 
        // mid : 1 + 4 -> 5 (num of ops req to have pen 5 is <= max ops valid )
        // 

        // 2 4 8 2
        // n : 4 start : 1, end : 8 , mid : 1 + 3 : 4 
        // mx : 8 : s1 : 4 s2 : 4 max heap 


        int start = 1;
        int n = nums.size();
        int end = *max_element(nums.begin(), nums.end());

        int ans = -1;

        while(start <= end){
            int mid = start + (end-start)/2;
            if(isValid(mid, nums, maxOperations)){
                ans = mid;
                end = mid-1;
            }else {
                start = mid+1;
            }
        }
        return ans;
    }