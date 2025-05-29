// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int n = nums.size();
    
            int sum = 0;
            int minLen = INT_MAX;
    
            int i = 0;
            int j = 0;
    
            while(j < n){
                sum += nums[j];
    
                while(sum >= target && i <=j){
                    minLen = min(minLen, j-i+1);
                    sum -= nums[i];
                    i++;
                }
    
                j++;
            }
    
            if(minLen == INT_MAX){
                return 0;
            }
    
            return minLen;
        }
    };