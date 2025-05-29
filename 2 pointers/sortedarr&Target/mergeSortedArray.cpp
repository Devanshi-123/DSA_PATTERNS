// https://leetcode.com/problems/merge-sorted-array/

// Time Complexity: O(n+mlogn+m)
// Space Complexity: O(1)
// Approach:
// 1. Use two pointers to compare the elements of nums1 and nums2.
// 2. If the element in nums1 is greater than the element in nums2, swap them.
// 3. Sort the first m elements of nums1 and the entire nums2.
// 4. Finally, copy the elements of nums2 to nums1 starting from index m.
// 5. The final merged array will be in nums1.

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // two pointer 
    int i = m-1;
    int j = 0;

    while(i >= 0 && j < n){
        if(nums1[i] > nums2[j]){
            swap(nums1[i], nums2[j]);
        }
        i--;
        j++;
    }

    sort(nums1.begin(), nums1.begin()+m);
    sort(nums2.begin(), nums2.end());

    j = 0;
    i = m;

    while(j < n && i < n+m){
        nums1[i++] = nums2[j++];
    }
    
}