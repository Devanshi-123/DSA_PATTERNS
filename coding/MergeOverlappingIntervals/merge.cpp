// https://leetcode.com/problems/merge-intervals/

// Time Complexity: O(n log n) sort 
// Space Complexity: O(n) for storing the merged intervals

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>>ans;
    int n = intervals.size();

    sort(intervals.begin(), intervals.end());

    ans.push_back(intervals[0]);
    int j = 0;

    for(int i = 1; i< n;i++){
        if(intervals[i][0] <= ans[j][1]){
            ans[j][0] = min(ans[j][0], intervals[i][0]);
            ans[j][1] = max(ans[j][1], intervals[i][1]);
        }else {
            ans.push_back(intervals[i]);
            j++;
        }
    }

    return ans;
}