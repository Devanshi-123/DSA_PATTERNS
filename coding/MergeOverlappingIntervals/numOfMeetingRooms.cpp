// https://leetcode.com/problems/meeting-rooms-ii/

// // Time Complexity: O(n log n) sort
// // Space Complexity: O(n) for min heap 



int minMeetingRooms(vector<vector<int>>& intervals) {
    int n = intervals.size();

    if(n == 1){
        return 1;
    }

    sort(intervals.begin(), intervals.end(), [](vector<int>a, vector<int>b){
        return a[0] < b[0];
    });

    // min. heap 

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

    pq.push({intervals[0][1], intervals[0][0]});

    int numOfRooms = 1;

    for(int i = 1; i<n;i++){
        int startTimeNextMeeting = intervals[i][0];
        int endTimeOfPrev = pq.top().first;

        if(startTimeNextMeeting >= endTimeOfPrev){
            pq.pop();
            pq.push({intervals[i][1], startTimeNextMeeting});
        }else {
            numOfRooms++;
            pq.push({intervals[i][1], startTimeNextMeeting});
        }
    }

    return numOfRooms;
}