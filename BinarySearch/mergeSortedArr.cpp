// https://leetcode.com/problems/median-of-two-sorted-arrays/

double helper(vector<int>& nums1, vector<int>& nums2, int n1, int n2, int numLeftElem){
        int start = 0;
        int end = n1;

        if(n1 <= n2){
            end = n1;
            while(start <= end){
                int mid1 = start + (end-start)/2;
                int mid2 = numLeftElem - mid1;

                int l1 = INT_MIN;
                if(mid1 > 0){
                    l1 = nums1[mid1-1];
                }
                int l2 = INT_MIN;
                if(mid2 > 0){
                    l2 = nums2[mid2-1];
                }
                int r1 = INT_MAX;
                if(mid1 < n1){
                    r1 = nums1[mid1];
                }
                int r2 = INT_MAX;
                if(mid2 < n2){
                    r2 = nums2[mid2];
                }

                if(l1 <= r2 && l2 <= r1){
                    if((n1+n2) % 2 == 0){
                        return (max(l1, l2) + min(r1, r2))/2.0;
                    }
                    return (double)max(l1, l2);
                }else if(l1 > r2){
                    end = mid1-1;
                }else {
                    start = mid1+1;
                }

            }
        }else {
            end = n2;
            while(start <= end){
                int mid2 = start + (end-start)/2;
                int mid1 = numLeftElem - mid2;

                int l1 = INT_MIN;
                if(mid1 > 0){
                    l1 = nums1[mid1-1];
                }
                int l2 = INT_MIN;
                if(mid2 > 0){
                    l2 = nums2[mid2-1];
                }
                int r1 = INT_MAX;
                if(mid1 < n1){
                    r1 = nums1[mid1];
                }
                int r2 = INT_MAX;
                if(mid2 < n2){
                    r2 = nums2[mid2];
                }

                if(l1 <= r2 && l2 <= r1){
                    if((n1+n2) % 2 == 0){
                        return (max(l1, l2) + min(r1, r2))/2.0;
                    }
                    return (double)max(l1, l2);
                }else if(l1 > r2){
                   start = mid2 + 1;
                }else {
                    end = mid2 - 1;
                }

            }
        }



        return -1;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int totalLen = n1 + n2;

        int numLeftElem = 0;

        if(totalLen %2 == 0){
            numLeftElem = totalLen/2;
        }else {
            numLeftElem = (totalLen+1)/2;
        }

        return helper(nums1, nums2, n1, n2, numLeftElem);
    }