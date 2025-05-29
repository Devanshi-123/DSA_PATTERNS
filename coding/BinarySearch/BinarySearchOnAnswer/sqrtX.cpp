// https://leetcode.com/problems/sqrtx/

int mySqrt(int x) {
        if(x <= 1){
            return x;
        }

        // create search space : search on ans 
        int start = 0;
        int end = x/2;

        while(start <= end){
            long long mid = start + (end-start)/2;

            if(mid*mid == (long long)x){
                return mid;
            }else if(mid*mid > x){
                end = mid-1;
            }else {
               start = mid+1;
            }
        }

        return end;
    }