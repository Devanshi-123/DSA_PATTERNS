// https://leetcode.com/problems/count-symmetric-integers

// 1. Given a range [low, high], count the number of symmetric integers in that range.
// 2. A symmetric integer is defined as an integer that can be represented as a sum of two equal parts.
// 3. For example, 121 is symmetric because 1 + 2 = 2 + 1.

// Time : O((high - low)*high)
// Space : O(high - low)

class Solution {
    private:
        bool isSymm(int n){
            int numDigits = 0;
            vector<int>vec;
            int firstHalf = 0;
            int secondHalf = 0;
    
            while(n > 0){
                int x = n%10;
                n = n/10;
                vec.push_back(x);
                numDigits++;
            }
    
            if(numDigits %2 != 0){
                return false;
            }
    
            for(int i = 0; i<numDigits/2; i++){
                secondHalf += vec[i];
            }
    
            for(int i = numDigits/2; i<numDigits; i++){
                firstHalf += vec[i];
            }
    
            return firstHalf == secondHalf;
    
        }
    public:
        int countSymmetricIntegers(int low, int high) {
            // low , high >= 0
            // x -> 2*n -> symm : sum of first n == sum of last n 
            int count = 0;
    
            for(int i = low; i<=high; i++){
                if(isSymm(i)){
                    count++;
                }
            }
            return count;
        }
    };