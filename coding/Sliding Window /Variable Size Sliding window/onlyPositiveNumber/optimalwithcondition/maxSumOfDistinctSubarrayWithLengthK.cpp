// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/

// O(n)
// O(1) Space 

class Solution {
    public:
        long long maximumSubarraySum(vector<int>& nums, int k) {
            // nums 
            // k 
            // maxm subarray sum of all subarrays : length k, unique elem 
    
            long long maxSum = 0;
            int n = nums.size();
    
            int i = 0;
            int j = 0;
    
            long long sum = 0;
            unordered_map<int,int>freq;
    
            while(j < n){
                freq[nums[j]]++;
                sum += nums[j];
    
                // invalid 
                while((freq.size() < j-i+1 || j-i+1 > k) && i<=j){
                    if(freq[nums[i]] > 1){
                        freq[nums[i]]--;
                    }else {
                        freq.erase(nums[i]);
                    }
                    sum -= nums[i];
    
                    i++;
                }
    
                // valid 
                if(j-i+1 == k && freq.size() == k){
                    maxSum = max(maxSum, sum);
                }
    
                j++;
            }
    
            return maxSum;
        }
    };