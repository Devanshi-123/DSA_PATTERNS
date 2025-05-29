// whether able to reach end or not 

// https://leetcode.com/problems/jump-game/submissions/1621773532/

// O(n)
// O(1)

bool canJump(vector<int>& nums) {
    int n = nums.size();

    if(n == 1){
        return true;
    }

    int i = 0;
    int farthestIdx = 0;

    while(i <= farthestIdx && farthestIdx < n){
        farthestIdx = max(farthestIdx, i+nums[i]);
        if(farthestIdx >= n-1){
            return true;
        }
        i++;
    }

    return false;
}