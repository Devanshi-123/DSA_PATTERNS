// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element

// O(n)
// O(1)

class Solution {
    public:
        int longestSubarray(vector<int>& nums) {
            int n = nums.size();
    
            if(n <= 1){
                return 0;
            }
    
            int i = 0;
            int j = 0;
    
            int maxLen = 0;
            int countOnes = 0;
            int countZeroes = 0;
    
            for(int i = 0; i<n;i++){
                if(nums[i] == 0){
                    countZeroes++;
                }
            }
    
            if(countZeroes <= 1){
                return n-1;
            }
    
            while(j < n){
                if(nums[j] == 1){
                    countOnes++;
                }
    
                // invalid 
                while(j-i+1 - countOnes > 1 && i<=j){
                    if(nums[i] == 1){
                        countOnes--;
                    }
                    i++;
                }
    
                if(j-i+1 - countOnes < 1){
                    maxLen = max(maxLen, j-i+1);
                }else if(j-i+1 - countOnes == 1){
                    maxLen = max(maxLen, j-i);
                }
    
                j++;
            }
            return maxLen;
        }
    };