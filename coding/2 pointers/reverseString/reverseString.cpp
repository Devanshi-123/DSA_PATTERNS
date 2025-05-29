// https://leetcode.com/problems/reverse-string/submissions/1621046768/

// O(n)
// O(1)

void reverseString(vector<char>& s) {
    int n = s.size();
    if(n == 1){
        return;
    }

    int i = 0; 
    int j = n-1;

    while(i < j){
        swap(s[i++], s[j--]);
    }
}