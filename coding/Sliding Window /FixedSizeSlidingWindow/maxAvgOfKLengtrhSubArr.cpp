// https://leetcode.com/problems/maximum-average-subarray-i/

double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();

    int i,j;
    i=j=0;

    int sum;
    double avg;
    sum= 0;
    avg = 0.0;
    double mxAvg = -std::numeric_limits<double>::max();

    // 1, 12, -5, -6, 50, 3
    // k= 4
    // sum : 51
    // avg : 12.75

    while(j < n){
        sum += nums[j];
        avg = static_cast<double>(sum)/(j-i+1);

        while(j-i+1 > k){
            sum -= nums[i];
            i++;
            avg = static_cast<double>(sum)/(j-i+1);
        }

        if(j-i+1 == k){
            mxAvg = max(mxAvg,avg);
        }

        j++;
    }

    return mxAvg;
}