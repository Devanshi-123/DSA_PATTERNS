// https://leetcode.com/problems/longest-palindromic-substring/

// O(n^2)
// O(1)
 
string longestPalindrome(string s) {
    int n = s.size();
    int maxLen = 0;
    int left = 0;
    int right = 0;
    string res = "";


    for(int i = 0; i<n;i++){
        // for odd length 
        left = i;
        right = i;
        while(left >= 0 && right <= n-1 && s[left] == s[right]){
            if(right - left +1 > maxLen){
                maxLen = right - left + 1;
                res = s.substr(left, right-left+1);
            }
            right++;
            left--;
        }

        // for even length 
        left = i;
        right = i+1;
         while(left >= 0 && right <= n-1 && s[left] == s[right]){
            if(right - left +1 > maxLen){
                maxLen = right - left + 1;
                res = s.substr(left, right-left+1);
            }
            left--;
            right++;
        }
    }

    return res;
}