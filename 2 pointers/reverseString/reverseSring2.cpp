// https://leetcode.com/problems/reverse-string-ii/

string reverseStr(string s, int k) {
    int n = s.size();

    if(k >= n){
        reverse(s.begin(), s.end());
        return s;
    }

    int i = 0;
    int j = 0;

    string str = "";

    for(int i = 0; i<n;i+=2*k){
        if(i+k < n){
            reverse(s.begin()+i, s.begin()+i+k);
        }else {
            reverse(s.begin()+i, s.end());
        }
    }

    return s;
}