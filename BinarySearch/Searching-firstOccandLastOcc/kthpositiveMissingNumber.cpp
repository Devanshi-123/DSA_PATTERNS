// https://leetcode.com/problems/kth-missing-positive-number/submissions/1641849896/

// Time : O(nlogn)
// Space : O(1)

 bool bs(vector<int> &arr,int n,int target) {
        int start = 0;
        int end = n-1;

        while(start <= end){
            int mid = start + (end-start)/2;

            if(arr[mid] == target){
                return true;
            }else if(arr[mid] < target){
                start = mid+1;
            }else {
                end = mid-1;
            }
        }

        return false;
    }
    int findKthPositive(vector<int>& arr, int k) {
        // arr 
        // integers : >= 0 
        // strictly increasing : sorted , unique 

        // k 

        // 2, 3, 4, 7, 11 
        // 5 

        int i = 1;
        int count = 0;

        int n = arr.size();

        while(count < k){
            if(bs(arr, n, i) == false){
                count++;
            }

            if(count == k){
                return i;
            }
            i++;
        }

        return -1;
    }

// Concept : the number of missing elem till an index i is equal to arr[i] - (i+1)
// so we can use binary search to find the kth missing elem

// Time : O(logn)
// Space : O(1)

int findKthPositive(vector<int>& arr, int k) {
        int start = 0;
        int n = arr.size();

        int end = n-1;

        while(start <= end){
            int mid = start + (end-start)/2;

            cout << "mid" << mid << endl;

            if((arr[mid]-(mid+1)) < k){
                start = mid+1;
            }else {
                end = mid-1;
            }
        }

        return start+k;
    }