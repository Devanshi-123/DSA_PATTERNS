// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/

// Time Complexity: O(n)
// Space Complexity: O(n)

string smallestSubsequence(string s) {
    int n = s.size();

    stack<char>st;

    unordered_map<char, int>freqMap;
    unordered_map<char,int>inStack;

    for(char ch : s){
        freqMap[ch]++;
    }

    for(char ch : s){
        if(inStack.find(ch) != inStack.end()){
            if(freqMap[ch] > 1){
                freqMap[ch]--;
            }
            continue;
        }

        while(!st.empty() && ch < st.top() && freqMap[st.top()] > 1){
            freqMap[st.top()]--;
            inStack.erase(st.top());
            st.pop();
        }

        st.push(ch);
        inStack[ch] = 1;
    }

    string str = "";

    while(!st.empty()){
        char ch = st.top();
        st.pop();
        str += ch;
    }

    reverse(str.begin(), str.end());

    return str;
}