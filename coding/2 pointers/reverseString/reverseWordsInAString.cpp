// https://leetcode.com/problems/reverse-words-in-a-string-iii/submissions/1621053753/

string reverseWords(string s) {
    int n = s.size();

    if(n == 1){
        return s;
    }

    stringstream ss(s);
    string word;
    string str = "";

    while(getline(ss, word, ' ')){
        reverse(word.begin(), word.end());
        str += word + ' ';
    }

    str.pop_back();

    return str;
}