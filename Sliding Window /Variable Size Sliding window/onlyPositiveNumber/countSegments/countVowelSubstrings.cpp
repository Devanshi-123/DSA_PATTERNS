// https://leetcode.com/problems/count-vowel-substrings-of-a-string/description/?envType=company&envId=google&favoriteSlug=google-thirty-days

// Time : O(n2)
// Space : O(1)

bool isVowel(char ch){
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}
int countVowelSubstrings(string word) {
    int count = 0;
    int n = word.size();

    for(int i = 0; i< n;i++){
        // till we get a vowel kkep on moving i 
        if(!isVowel(word[i])){
            i++;
        }

        // for each vowel segment maintain a set 
        unordered_set<int>s;
        for(int j = i; j<n;j++){
            if(!isVowel(word[j])){
                break;
            }
            s.insert(word[j]);
            if(s.size() == 5){
                count++;
            }
        }
    }
    return count;
}