// https://leetcode.com/problems/container-with-most-water/?envType=company&envId=google&favoriteSlug=google-all

int maxArea(vector<int>& height) {
    int n = height.size();

    if(n <= 1){
        return 0;
    }

    int start = 0;
    int end = n-1;

    int water = 0;

    while(start <= end){
        water = max(water, min(height[start], height[end])*(end - start));
        if(height[start] <= height[end]){
            start++;
        }else {
            end--;
        }
    }

    return water;
}