// https://leetcode.com/problems/first-bad-version/submissions/1641279181/?envType=problem-list-v2&envId=binary-search

// Time Complexity: O(log n)
// Space Complexity: O(1)

 int firstBadVersion(int n) {
        int start = 1;
        int end = n;

        int firstBad = -1;

        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(isBadVersion(mid)) {
                firstBad = mid;
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        return firstBad;
   }