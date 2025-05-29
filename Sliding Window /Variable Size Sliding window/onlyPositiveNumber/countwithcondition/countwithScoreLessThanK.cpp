// https://leetcode.com/problems/count-subarrays-with-score-less-than-k/description/

// Time : O(n)
// Space : O(1)

long long countSubarrays(vector<int>& nums, long long k) {
    long long n = nums.size();

    long long i = 0;
    long long j = 0;
    long long score = 1;
    long long sum = 0;
    long long count = 0;

    while(j < n){
        // calc 
        sum += nums[j];
        score = sum * (j-i+1);

        // while invalid 
        while(score >= k && i <= j){
            sum -= nums[i];
            i++;
            score = sum*(j-i+1);
        }

        count += j-i+1;
        j++;
    }

    return count;
}