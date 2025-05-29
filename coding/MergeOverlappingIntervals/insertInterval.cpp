// https://leetcode.com/problems/insert-interval/description/

// Time Complexity: O(n log n) sort
// Space Complexity: O(n) for storing the merged intervals

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>>& intervals){
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
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    // insert a new interval 

    // already sort 

    int n = intervals.size();

    // Spca e: O(1)

    if(n == 0){
        intervals.push_back(newInterval);
        return intervals;
    }

    int start = newInterval[0];
    int end = newInterval[1];

    for(int i = 0; i<n; i++){
        if(start <= intervals[i][1] && end >= intervals[i][0]){
            intervals[i][0] = min(start, intervals[i][0]);
            intervals[i][1] = max(end, intervals[i][1]);
            vector<vector<int>>mergedIntervals = mergeOverlappingIntervals(intervals);
            return mergedIntervals;
        }
    }

    intervals.push_back(newInterval);
    vector<vector<int>>mergedIntervals = mergeOverlappingIntervals(intervals);
    return mergedIntervals;
}