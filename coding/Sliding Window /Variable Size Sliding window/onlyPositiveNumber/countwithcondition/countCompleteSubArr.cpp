// https://leetcode.com/problems/count-complete-subarrays-in-an-array/?envType=company&envId=google&favoriteSlug=google-thirty-days

// Time : O(n)
// Space : O(n)

int helper(vector<int>&nums, int totalDist, int n){
    // cond : size of freq must be equal to the totalDist 

    int i = 0;
    int j = 0;
    unordered_map<int,int>freq;
    int count = 0;

    while(j < n){
        freq[nums[j]]++;

        while(freq.size() > totalDist && i<=j){
            if(freq[nums[i]] > 1){
                freq[nums[i]]--;
            }else {
                freq.erase(nums[i]);
            }
            i++;
        }

        count += j-i+1;

        j++;
    }

    return count;
}
int countCompleteSubarrays(vector<int>& nums) {
    unordered_map<int,int>totalFreq;

    int n = nums.size();

    if(n <= 1){
        return 1;
    }

    for(int i = 0; i<n;i++){
        totalFreq[nums[i]]++;
    }
    int totalDist = totalFreq.size();
    return helper(nums, totalDist, n) - helper(nums, totalDist-1, n);

}