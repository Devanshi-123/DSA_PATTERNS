// https://leetcode.com/problems/longest-mountain-in-array

// O(n) time and O(n) space

class Solution {
    public:
        int longestMountain(vector<int>& arr) {
            int n = arr.size();
    
            int maxlen = 0;
    
            if(n < 3){
                return 0;
            }
    
            vector<int>onLeft(n+1, 0);
            vector<int>onRight(n+1, 0);
    
            for(int i = 1; i<n;i++){
                if(arr[i-1] < arr[i]){
                    onLeft[i] = 1 + onLeft[i-1];
                }else {
                    onLeft[i] = 0;
                }
            }
    
            for(int i = n-2; i>=0;i--){
                if(arr[i] > arr[i+1]){
                    onRight[i] = onRight[i+1] + 1;
                }else {
                    onRight[i] = 0;
                }
            }
    
            for(int i = 0; i<n;i++){
                if(onLeft[i] != 0 && onRight[i] != 0){
                    maxlen = max(maxlen, onLeft[i]+onRight[i]+1);
                }
            }
    
            return maxlen;
        }
    };