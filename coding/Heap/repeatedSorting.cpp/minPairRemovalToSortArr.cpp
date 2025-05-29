// Approach 1 : Brute force 

// Time : O(n^3)
// Space : O(1)

class Solution {
    private:
       bool isSorted(vector<int>&nums){
            int n = nums.size();
    
            for(int i = 0; i<n-1;i++){
                if(nums[i] > nums[i+1]){
                    return false;
                }
            }
    
            return true;
        }
    public:
        int minimumPairRemoval(vector<int>& nums) {
            int n = nums.size();
            if(n == 1 || isSorted(nums)){
                return 0;
            }
    
            int count = 0;
    
            while(nums.size() > 1 && !isSorted(nums)){
                int a = -1;
                int b = -1;
                int minSum = INT_MAX;
    
                for(int i = 0; i<nums.size()-1; i++){
                    int sum = nums[i] + nums[i+1];
                    if(sum < minSum){
                        minSum = sum;
                        a = i;
                        b = i+1;
                    }
                }
    
                nums.erase(nums.begin()+a);
                nums[a] = minSum;
                count++;
            }
    
            return count;
        }
    };

// Approach 2 : Using priority queue

// Time : O(nlogn)
// Space : O(n)

#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        // Structure to store adjacent pair (sum, index)
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        
        // Mark deleted indices
        vector<bool> deleted(n, false);

        // Prepare heap
        for (int i = 0; i < n-1; ++i) {
            minHeap.push({nums[i] + nums[i+1], i});
        }

        int count = 0;
        while (true) {
            bool sorted = true;
            for (int i = 0; i < n-1; ++i) {
                if (!deleted[i] && !deleted[i+1] && nums[i] > nums[i+1]) {
                    sorted = false;
                    break;
                }
            }
            if (sorted) break;

            // Remove invalid heap tops
            while (!minHeap.empty()) {
                auto [sum, idx] = minHeap.top();
                if (deleted[idx] || deleted[idx+1]) {
                    minHeap.pop();
                } else {
                    break;
                }
            }

            auto [minSum, idx] = minHeap.top();
            minHeap.pop();

            // Merge idx and idx+1
            nums[idx] = minSum;
            deleted[idx+1] = true;

            // Update adjacent sums
            if (idx > 0 && !deleted[idx-1]) {
                minHeap.push({nums[idx-1] + nums[idx], idx-1});
            }
            if (idx+1 < n-1 && !deleted[idx+2]) {
                minHeap.push({nums[idx] + nums[idx+2], idx});
            }

            count++;
        }

        return count;
    }
};
