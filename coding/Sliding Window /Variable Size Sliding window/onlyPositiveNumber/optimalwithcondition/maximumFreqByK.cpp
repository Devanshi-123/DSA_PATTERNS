// https://leetcode.com/problems/frequency-of-the-most-frequent-element/?

// Time : O(nlogn)
// Space : O(n)

int maxFrequency(vector<int>& nums, int k) {
    int n = nums.size();

    if(n == 1){
        return 1;
    }

    sort(nums.begin(), nums.end());

    // since optimal : sort(greedy) + sliding window 

    int i = 0;
    int j = 0;
    long long sum = 0;
    vector<int>freq(n+1, 1);

    while(j < n-1){
        sum += nums[j];

        while((((long long)nums[j+1]*(j-i+1)) - sum) > k && i <= j){
            sum -= nums[i];
            i++;
        }

        if((((long long)nums[j+1]*(j-i+1)) - sum) <= k){
            freq[j+1] += j-i+1;
        }

        j++;
    }

    int maxFreq = 1;

    for(auto fr : freq){
        maxFreq = max(maxFreq, fr);
    }

    return maxFreq;
}