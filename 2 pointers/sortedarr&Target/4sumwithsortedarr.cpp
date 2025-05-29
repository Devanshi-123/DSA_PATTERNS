// link : https://leetcode.com/problems/4sum/

// Time : O(n^3)
// Space : O(n) 
// Approach : 2 pointers


class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>&nums, int start, int end, int sum){
            int n = nums.size();
            vector<vector<int>>triplets;
            set<vector<int>>setTrip;
            vector<int>vec;
    
            for(int i = start; i<end-2; i++){
                long long target = (long long)sum - (long long)nums[i];
    
                int j = i+1;
                int k = end-1;
    
                while(j < k){
                    if(nums[j]+ nums[k] == target){
                        vec.push_back(nums[i]);
                        vec.push_back(nums[j]);
                        vec.push_back(nums[k]);
                        setTrip.insert(vec);
                        j++;
                        k--;
                        vec.clear();
                    }else if(nums[j] + nums[k] < target){
                        j++;
                    }else {
                        k--;
                    }
                }
            }
    
            for(auto elem : setTrip){
                triplets.push_back(elem);
            }
    
            return triplets;
        }
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            int n = nums.size();
    
            sort(nums.begin(), nums.end());
    
            set<vector<int>>quadSet;
            vector<vector<int>>quads;
            vector<vector<int>>triplets;
            vector<int>vec;
    
            for(int i = 0; i<n-3; i++){
                int newTarget = target - nums[i];
                triplets = threeSum(nums , i+1, n, newTarget);
                for(auto triplet : triplets){
                    vec.push_back(nums[i]);
                    vec.push_back(triplet[0]);
                    vec.push_back(triplet[1]);
                    vec.push_back(triplet[2]);
                    quadSet.insert(vec);
                    vec.clear();
                }
                triplets.clear();
            }
    
            for(auto quad : quadSet){
                quads.push_back(quad);
            }
    
            return quads;
        }
    };