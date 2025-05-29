// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/

// O(n)
// O(n)

class Solution {
    public:
        int shortestSubarray(vector<int>& nums, int k) {
            // since both neg and pos elem so prefix sum arr 
            // deque 
    
            int n = nums.size();
            vector<long long>prefix(n+1, 0);
    
            for(int i = 0; i<n;i++){
                prefix[i+1] = nums[i] + prefix[i];
            }
    
            deque<int>dq;
            int res = INT_MAX;
            // in front we maintain the idx of all elem we want 
            // if we find any elem greater remove as we want to store the idx acc to elem in increasing order
    
            // 2 -1 2
            // 0 2 1 3 
            for(int i = 0; i<=n;i++){
                while(!dq.empty() && prefix[i] < prefix[dq.back()]){
                    dq.pop_back();
                }
    
                while(!dq.empty() && prefix[i] - prefix[dq.front()] >= k){
                    res = min(res, i - dq.front());
                    dq.pop_front();
                }
    
                dq.push_back(i);
            }
    
            //  2 3
    
            if(res == INT_MAX){
                return -1;
            }
    
            return res;
        }
    };