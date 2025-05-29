// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/submissions/1642617598/

// Time : O(nlogn)
// Space : O(1)

class Solution {
public:
    // input : 
    // days : shipped 
    // capacity of ship : capacity of day : we load items in increasing order of weigths 

    // output : 
    // min capacity for each day to ship all the items within days days

    // example : 
    // weights : [1,2,3,4,5,6,7,8,9,10] : sorted 
    // days : 5
    bool isValid(vector<int> &weights, int days, int capacity, int n){
        if(capacity < *max_element(weights.begin(), weights.end())){
            return false;
        }
        int daysReq = 0;
        int sum = 0;

        for(int i = 0; i<n;i++){
            if(sum + weights[i] > capacity){
                sum = 0;
                daysReq++;
            }
            sum += weights[i];
        }

        if(sum != 0){
            sum = 0;
            daysReq++;
        }

        cout << "dr" << daysReq << "total" << days << endl;

        return daysReq <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        // create search space 
        int totalWeights = 0;

        for(int i = 0; i<n;i++){
            totalWeights += weights[i];
        }

        int start = weights[0];
        int end = totalWeights;

        int ans = -1;

        while(start <= end){
            int mid = start + (end-start)/2;

            cout << "mid" << mid << endl;

            if(isValid(weights, days, mid, n)){
                ans = mid;
                end = mid-1;
            }else {
                start = mid+1;
            }
        }

        return ans;
    }
};