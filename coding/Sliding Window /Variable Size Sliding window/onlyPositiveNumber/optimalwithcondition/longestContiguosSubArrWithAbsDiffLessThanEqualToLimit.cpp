// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/

// O(nlogn) time and O(n) space

class Solution {
    public:
        int longestSubarray(vector<int>& nums, int limit) {
            int n = nums.size();
    
            if(n == 1){
                return 1;
            }
    
            multiset<int>s;
    
            int i = 0;
            int j = 0;
            int mxLen = 0;
    
            while(j < n){
                s.insert(nums[j]);
    
                int mn = *s.begin();
                int mx = *--s.end();
    
                while(abs(mn-mx) > limit && i<=j){
                    auto it = s.find(nums[i]);
                    s.erase(it);
                    i++;
                    mn = *s.begin();
                    mx = *--s.end();
                }
    
                if(abs(mn-mx) <= limit){
                    mxLen = max(mxLen, j-i+1);
                    cout << "ml" << mxLen << endl;
                }
    
                j++;
            }
    
            return mxLen;
        }
    };

// Variation : https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/submissions/1624269511/

class Solution {
    public:
        int maximumBeauty(vector<int>& nums, int k) {
            // nums : 0 indexed 
            // k >= 0 
            // choose i which is not vis from 0 to n-1 
    
            // 4 6 1 2 3 3 5 7 8 2 
            // 1 2 2 3 3 4 5 6 7 8 
    
            // maxm subarray such that diff btw any two <= 2*k
    
            int n = nums.size();
            if(n <= 1){
                return n;
            }
    
            sort(nums.begin(), nums.end());
            multiset<int>ms;
    
            int i = 0;
            int j = 0;
    
            int mn,mx;
            mn = mx = 0;
    
            int maxLen = 0;
    
            while(j < n){
                ms.insert(nums[j]);
    
                mn = *ms.begin();
                mx = *--ms.end();
    
                while(abs(mx-mn) > 2*k && i<=j){
                    auto it = ms.find(nums[i]);
                    ms.erase(it);
                    i++;
                    mn = *ms.begin();
                    mx = *--ms.end();
                }
    
                if(abs(mx-mn) <= 2*k){
                    maxLen = max(maxLen, j-i+1);
                }
    
                j++;
            }
            return maxLen;
        }
    };