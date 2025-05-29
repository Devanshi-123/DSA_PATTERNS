// https://leetcode.com/problems/add-digits/submissions/1620273064/

class Solution {
    private:
        pair<int,int> sumOfDigits(int n){
            int sum = 0;
            int count = 0;
            while(n > 0){
                int x = n%10;
                sum += x;
                n = n/10;
                count += 1;
            }
            return {sum, count};
        }
    public:
        int addDigits(int num) {
            if(num == 1 || num == 0){
                return num;
            }
            if(sumOfDigits(num).second == 1){
                return num;
            }
    
            int slow = num;
            int fast = num;
            int slowCount = 0;
            int fastCount = 0;
    
            while(fastCount != 1){
                slowCount = sumOfDigits(slow).second;
                fastCount = sumOfDigits(sumOfDigits(fast).first).second;
                slow = sumOfDigits(slow).first;
                fast = sumOfDigits(sumOfDigits(fast).first).first;
                if(fastCount == 1){
                    return fast;
                }
            }
            return -1;
        }
    };