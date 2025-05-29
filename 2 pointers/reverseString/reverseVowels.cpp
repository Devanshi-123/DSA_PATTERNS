// https://leetcode.com/problems/reverse-vowels-of-a-string/submissions/1621051516/

bool isVowel(char ch){
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}
public:
string reverseVowels(string s) {
    int n = s.size();
    if(n == 1){
        return s;
    }

    int i = 0;
    int j = n-1;

    while(i <= j){
        if(isVowel(s[i]) && isVowel(s[j])){
            swap(s[i], s[j]);
            i++;
            j--;
        }else if(!isVowel(s[i]) && isVowel(s[j])){
            i++;
        }else if(!isVowel(s[j]) && isVowel(s[i])){
            j--;
        }else {
            i++;
            j--;
        }
    }
    return s;
}