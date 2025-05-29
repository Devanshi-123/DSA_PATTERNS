// https://leetcode.com/problems/subarrays-with-k-different-integers

class Solution {
    public:
        int subarraysWithAtmostKDistinct(vector<int>& nums, int k){
            int i,j;
            i=j=0;
            int n = nums.size();
            unordered_map<int,int>freq;
    
            int count = 0;
            while(j < n){
                // calc 
                freq[nums[j]]++;
    
                // if you have more than k distinct elements
                while(freq.size() > k){
                    if(freq[nums[i]] == 1){
                        freq.erase(nums[i]);
                    }
                    else{
                        freq[nums[i]]--;
                    }
                    i++;
                }
    
                count += j-i+1;
                j++;
            }
            return count;
        }
        int subarraysWithKDistinct(vector<int>& nums, int k) {
            return subarraysWithAtmostKDistinct(nums, k) - subarraysWithAtmostKDistinct(nums, k-1);
        }
    };