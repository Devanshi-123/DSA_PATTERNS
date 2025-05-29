// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/

// Time : O(n*k)
// Space : O(n)

class Solution {
    private:
        int findPower(vector<int>&vec){
            int n = vec.size();
            if(n == 1){
                return vec[0];
            }
            int prev = vec[0];
    
            for(int i = 1; i<n;i++){
                if(vec[i] == prev+1){
                    prev = vec[i];
                }else {
                    return -1;
                }
            }
    
            return prev;
        }
    public:
        vector<int> resultsArray(vector<int>& nums, int k) {
            int n = nums.size();
    
            // k >= 0
    
            // power 
            vector<int>vec;
            vector<int>result;
    
            int i = 0;
            int j = 0;
    
            while(j < n){
                vec.push_back(nums[j]);
    
                // invalid 
                while(j-i+1 > k){
                    vec.erase(vec.begin());
                    i++;
                }
    
                // valid 
                if(j-i+1 == k){
                    int powerNum = findPower(vec);
                    result.push_back(powerNum);
                }
    
                j++;
            }
    
            return result;
        }
    };