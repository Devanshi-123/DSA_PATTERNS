// https://leetcode.com/problems/word-ladder/
// O(n*l^2) time complexity
// O(n*l) space complexity
// where n is the number of words in the wordList and l is the length of each word


int bfs(queue<pair<string, int>> &q, unordered_map<string, int> &vis, unordered_map<string, int> &wordMap, int n, string endWord){
    while(!q.empty()){
        string currWord = q.front().first;
        int currCount = q.front().second;

        if(currWord == endWord){
            return currCount;
        }   

        q.pop();

        // explore choices 
        for(int j = 0; j < currWord.size(); j++){
            for(int i = 0; i<26; i++){
                if(i+'a' == currWord[j]){
                    continue;
                }

                string target = currWord;
                target[j] = i+'a';
                if(wordMap.find(target) != wordMap.end() && (vis.find(target) == vis.end())){
                    q.push({target, currCount+1});
                    vis[target] = 1;
                }
            }
        }
    }
    return 0;
}
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    // map from vector for easy searching 

    // if end word does not exist then false 0 

    // bfs 
    // q , vis -> map 

    if(beginWord == endWord){
        return 1;
    }

    unordered_map<string, int>wordMap;

    int n = wordList.size();

    for(int i = 0; i<n;i++){
        wordMap[wordList[i]]++;
    }

    if(wordMap.find(endWord) == wordMap.end()){
        return 0;
    }

    queue<pair<string, int>>q;
    unordered_map<string, int>vis;

    q.push({beginWord, 1});
    vis[beginWord] = 1;

    // single source bfs 
    // smallest path 

    return bfs(q, vis, wordMap, n, endWord);

}