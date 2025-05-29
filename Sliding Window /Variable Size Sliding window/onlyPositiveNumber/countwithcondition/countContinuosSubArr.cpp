// https://leetcode.com/problems/continuous-subarrays/description/

// Time complexity : O(nlogn)
// Space complexity : O(n)

class Solution {
    public:
        long long continuousSubarrays(vector<int>& nums) {
            // nums : 0 indexed 
            // cotinuos : 
            // count 
    
            int n = nums.size();
    
            long long count = 0;
    
            if(n <= 1){
                return n;
            }
    
            multiset<int>ms;
            int mx = 0;
            int mn = 0;
    
            int i = 0;
            int j = 0;
            int limit = 2;
    
    
            while(j < n){
                ms.insert(nums[j]);
                mx = *ms.begin();
                mn = *--ms.end();
    
                while(abs(mx-mn) > limit && i<=j){
                    auto it = ms.find(nums[i]);
                    ms.erase(it);
                    i++;
                    mx = *ms.begin();
                    mn = *--ms.end();
                }
    
                if(abs(mx-mn) <= limit){
                    count += j-i+1;
                }
    
                j++;
            }
            return count;
        }
    };