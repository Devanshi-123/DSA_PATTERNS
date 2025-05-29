// DP 

// memory limit exceeded 

class Solution {
    private:
        int helper(int left, int right, string s, vector<int>freq, int k, vector<vector<int>>&dp){
            //cc 
            int count = 0;
            for(int i = 0; i<3;i++){
                if(freq[i] >= k){
                    count++;
                }
            }
            if(count == 3){
                return 0;
            }
    
            // bc
            if(left > right){
                return INT_MAX;
            }
    
            if(dp[left][right] != -1){
                return dp[left][right];
            }
    
            // induction 
            freq[s[left] - 'a']++;
            int leftCount = helper(left+1, right, s, freq, k, dp);
            freq[s[left] - 'a']--;
            freq[s[right] - 'a']++;
            int rightCount = helper(left, right-1, s, freq, k, dp);
            freq[s[right] - 'a']--;
    
            int minCount = min(leftCount, rightCount);
    
            if(minCount == INT_MAX){
                return dp[left][right] = INT_MAX;
            }
    
            return dp[left][right] = 1+minCount;
    
        }
    public:
        int takeCharacters(string s, int k) {
            // string s -> a, b, c
            // k -> >=0 
            // every operation either left or right (choice)
    
            // min num of ops for atleast k of each character 
    
            int n = s.size();
    
            if(k == 0){
                return 0;
            }
    
            if(n < 3*k){
                return -1;
            }
    
            vector<int>freq(3, 0);
            vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
    
            int res = helper(0, n-1, s, freq, k, dp);
            if(res == INT_MAX){
                return -1;
            }
    
            return res;
        }
    };

// Sliding window 

