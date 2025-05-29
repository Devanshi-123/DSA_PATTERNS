// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/submissions/1642656164/

// Time : O(nlog(maxDays))
// Space : O(1)

bool isValid(int daysAvlbl, vector<int>& bloomDay, int m, int k, int n){
        int buoqMade = 0;

        int flowersUsed = 0;

        for(int i = 0; i<n;i++){
            if(bloomDay[i] <= daysAvlbl){
                flowersUsed++;
                if(flowersUsed == k){
                    buoqMade++;
                    flowersUsed = 0;
                }
            }else {
                flowersUsed = 0;
            }
        }

        return buoqMade >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        // bloomday : arr 
        // m 
        // k 

        // make m bouquets 
        // 1 bouque : k adjacent flowers 
        // n flowers : ith flower bloom acc to bloomday and can be used only in 1 buoque 

        // min days to make m buoque 

        //  1 10 3 10 2
        // 3
        // 1

        // sort : {1, 0}, {2, 4}, {3, 2}, {10, 1}, {10, 3}

        int start = *min_element(bloomDay.begin(),bloomDay.end());
        int end = *max_element(bloomDay.begin(),bloomDay.end());
        int n = bloomDay.size();

        int ans = -1;

        while(start <= end){
            int mid = start + (end-start)/2;

            if(isValid(mid, bloomDay, m, k, n)){
                ans = mid;
                end = mid-1;
            }else {
                start = mid+1;
            }
        }

        return ans;

    }