// https://leetcode.com/problems/guess-number-higher-or-lower/

// Time : O(logn)
// Space : O(1)

int guessNumber(int n) {
        // search space : since answer will be between 1 to n 
        // guess wrong : guess > trget 

        int start = 1;
        int end = n;

        while(start <= end){
            int mid = start + (end-start)/2;

            if(guess(mid) == 0){
                return mid;
            }else if(guess(mid) == -1){
                end = mid-1;
            }else {
                start = mid+1;
            }
        }

        return -1;

    }