// simulated the problem into house robber as if we deletre some element we cannot delete its adjacenet 

class Solution {
public:
    int houseRobber(vector<int>points){
        int n = points.size();

        vector<int>dp(n+1, 0);

        for(int i=0;i<n;i++){
            if(i == 0){
                dp[i] = points[0];
            } else if(i == 1){
                dp[i] = max(points[0], points[1]);
            }
        }

        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-2]+points[i], dp[i-1]);
        }

        return dp[n-1];
    }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();

        // maxm number of points 

        // pick and delete nums[i] : points + nums[i]

        // 3 4 2 
        // 4 3 2 

        // 2 2 3 3 3 4

        if(n == 0){
            return 0;
        }

        int mxElem = *max_element(nums.begin(), nums.end());

        vector<int>points(mxElem+1, 0);

        for(auto num: nums){
            points[num] += num;
        }

        return houseRobber(points);
    }
};