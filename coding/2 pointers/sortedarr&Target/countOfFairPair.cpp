// https://leetcode.com/problems/count-the-number-of-fair-pairs/?envType=company&envId=google&favoriteSlug=google-thirty-days

long long countFairPairs(vector<int>& nums, int lower, int upper) {
    int n = nums.size();

    long long count = 0;
    long long countLessThanUpper = 0;
    long long countLessThanLower = 0;

    if(n <= 1){
        return count;
    }

    // <= upper - < lower 

    sort(nums.begin(), nums.end());

    // 0 1 4 4 5 7 

    // 3 -> 0 4, 0 4, 0 5
    // 3 -> 1 4, 1 4, 1 5

    int j = n-1;
    int i = 0;

    while(i < j){
        if(nums[i] + nums[j] <= upper){
            countLessThanUpper += j - i;
            i++;
        }else {
            j--;
        }
    }
    i = 0;
    j = n-1;
     while(i < j){
        if(nums[i] + nums[j] < lower){
            countLessThanLower += j - i;
            i++;
        }else {
            j--;
        }
    }

    count += countLessThanUpper - countLessThanLower;
    return count;

}