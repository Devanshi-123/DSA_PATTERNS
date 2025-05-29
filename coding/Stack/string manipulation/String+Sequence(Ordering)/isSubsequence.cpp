// https://leetcode.com/problems/is-subsequence/description/

bool isSubsequence(string s, string t) {
    // stack 
    int n = s.size();
    int m = t.size();
    stack<char>st;

    for(int i = m-1; i>= 0; i--){
        st.push(t[i]);
    }

    int i = 0;

    while(!st.empty() && i < n){
        if(st.top() == s[i]){
            i++;
        }
        st.pop();
    }

    if(i < n){
        return false;
    }
    return true;
}