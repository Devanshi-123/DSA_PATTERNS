// https://leetcode.com/problems/meeting-rooms/description/

// Time Complexity: O(n log n) sort
// Space Complexity: O(1) for storing the merged intervals

bool canAttendMeetings(vector<vector<int>>& intervals) {
    int n = intervals.size();

    if(n <= 1){
        return true;
    }

    // an employee cannot attend all the meetings if any two meetimgs are overlapping 

    sort(intervals.begin(), intervals.end());

    for(int i = 0; i<n-1;i++){
        if(intervals[i+1][0] < intervals[i][1]){
            return false;
        }
    }

    return true;
}