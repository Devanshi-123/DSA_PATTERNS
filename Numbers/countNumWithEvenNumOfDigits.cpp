// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

class Solution {
    private:
        bool evenDigits(int n){
            int count = 0;
    
            while(n > 0){
                n = n/10;
                count++;
            }
    
            return count%2 == 0;
        }
    public:
        int findNumbers(vector<int>& nums) {
            int n = nums.size();
    
            int count = 0;
    
            for(int i = 0; i<n;i++){
                if(evenDigits(nums[i])){
                    count++;
                }
            }
            return count;
        }
    };