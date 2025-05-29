// https://leetcode.com/problems/fruit-into-baskets/

class Solution {
    public:
        int totalFruit(vector<int>& fruits) {
            int n = fruits.size();
    
            if(n <= 2){
                return n;
            }
    
            int i = 0;
            int j = 0;
    
            int maxNum = 0;
            int numFruits = 0;
            unordered_map<int,int>freq;
    
            while(j < n){
                numFruits++;
                freq[fruits[j]]++;
    
                // invalid
                while(freq.size() > 2 && i<=j){
                    if(freq[fruits[i]] > 1){
                        freq[fruits[i]]--;
                    }else {
                        freq.erase(fruits[i]);
                    }
                    numFruits--;
                    i++;
                }
    
                // valid 
                if(freq.size() <= 2){
                    maxNum = max(maxNum, numFruits);
                }
    
                j++;
            }
    
            return maxNum;
        }
    };