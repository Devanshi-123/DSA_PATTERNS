// https://leetcode.com/problems/reverse-words-in-a-string/description/

string reverseWords(string s) {
    stack<string>st;
    int n = s.size();

    if(n == 1){
        return s;
    }

    string str = "";
    stringstream ss(s);
    string word;

    while(getline(ss, word, ' ')){
        if(word.size() > 0){
            st.push(word);
        }
    }

    while(!st.empty()){
        str += st.top() + ' ';
        st.pop();
    }

    str.pop_back();

    return str;
}