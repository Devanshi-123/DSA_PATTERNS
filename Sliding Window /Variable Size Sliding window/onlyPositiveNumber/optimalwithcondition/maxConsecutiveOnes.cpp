// https://leetcode.com/problems/max-consecutive-ones-iii/

// O(n)
// O(1)

class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int n = nums.size();
    
            int numOnes = 0;
            int maxOnes = 0;
    
            int i = 0;
            int j = 0;
    
            while(j < n){
                if(nums[j] == 1){
                    numOnes++;
                }
    
                // invalid 
                while((j-i+1 - numOnes) > k && i<=j){
                    if(nums[i] == 1){
                        numOnes--;
                    }
                    i++;
                }
    
                // valid 
                if(j-i+1 - numOnes <= k){
                    maxOnes = max(maxOnes, j-i+1);
                }
    
                j++;
            }
    
            return maxOnes;
        }
    };