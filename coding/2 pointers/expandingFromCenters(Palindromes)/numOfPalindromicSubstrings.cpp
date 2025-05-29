// https://leetcode.com/problems/palindromic-substrings/submissions/1620962752/

// O(n^2)
// O(1)

int countSubstrings(string s) {
    // start expanding from center considering every index as center 
    int n = s.size();
    int left = 0;
    int right = 0;
    int count = 0;


for(int i = 0; i<n;i++){
    // for odd length 
    left = i;
    right = i;
    while(left >= 0 && right <= n-1){
        if(s[left] == s[right]){
             count++;
            right++;
            left--;
        }else {
            break;
        }
    }

    // for even length 
    left = i;
    right = i+1;
     while(left >= 0 && right <= n-1){
       if(s[left] == s[right]){
            count++;
            right++;
            left--;
        }else {
            break;
        }
    }
}

return count;
}