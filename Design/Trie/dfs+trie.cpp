// https://leetcode.com/problems/design-add-and-search-words-data-structure/

// Insert a word into the trie.
// Time : O(l)
// Space : O(n*l) : n is the number of words

// Search for a word in the trie. when it can have a wildcard
// Time : O(k*26*l) : k is the number of wildcards
// Space : O(l) : l is the length of the word and the maxm recursive stack space

// TRIE + DFS

class WordDictionary {
    struct Node{
        Node* links[26];
        bool isEndOfWord;
    
        Node(){
            for(int i = 0; i<26; i++){
                links[i] = nullptr;
            }
            isEndOfWord = false;
        }
    
        bool containsKey(char ch){
            return links[ch-'a'] != nullptr;
        }
    
        void put(char ch, Node* node){
            links[ch-'a'] = node;
        }
    };
    private: Node* root;
    public:
        WordDictionary() {
            root = new Node();
        }
        
        void addWord(string word) {
            Node* node = root;
            for(char ch : word){
                if(!node->containsKey(ch)){
                    Node* newnode = new Node();
                    node->put(ch, newnode);
                }
                node = node->links[ch-'a'];
            }
            node->isEndOfWord = true;
        }
    
        bool searchWordDFS(string word, int i, Node* node, int n){
            // base case 
            if(!node){
                return false;
            }
            if(i >= n){
                return node->isEndOfWord;
            }
            char ch = word[i];
            if(ch != '.'){
                if(node->containsKey(ch) == false){
                        return false;
                }
                node = node->links[ch-'a'];
                return searchWordDFS(word, i+1, node, n);
            }else {
                for(int j = 0; j<26; j++){
                    if(node->links[j] != nullptr){
                        if( searchWordDFS(word, i+1, node->links[j], n) == true){
                            return true;
                        }
                    }
                }
                return false;
            }
            return true;
        }
        
        bool search(string word) {
            Node* node = root;
            return searchWordDFS(word, 0, node, word.size());
        }
    };