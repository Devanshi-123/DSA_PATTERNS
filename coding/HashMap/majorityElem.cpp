//  link : https://leetcode.com/problems/majority-element/

// Approach 1 
 // approach 1: using sorting 
    // nlogn time 
    // O(1) space 

int majorityElement(vector<int>& nums) {
   

    int n = nums.size();

    sort(nums.begin(), nums.end());
    return nums[n/2];
}

// Approach 2
// approach 2: using hashmap 
    // O(n) time 
    // O(n) space
int majorityElement(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int>mp;

    for(int i = 0; i< n; i++){
        mp[nums[i]]++;
    }

    for(auto it: mp){
        if(it.second > n/2){
            return it.first;
        }
    }

    return -1;
}

// Approach 3
// approach 3: using Boyer-Moore Voting Algorithm
    // O(n) time 
    // O(1) space
int majorityElement(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    int candidate = -1;

    for(int i = 0; i< n; i++){
        if(count == 0){
            candidate = nums[i];
        }
        if(nums[i] == candidate){
            count++;
        }else{
            count--;
        }
    }

    return candidate;
}