// https://leetcode.com/problems/implement-trie-prefix-tree/

// n words 
// l length of each word
// O(l) time complexity for insert, search and startsWith of any word
// O(n*l*26) space complexity

struct Node {
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
private : Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
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
    
    bool search(string word) {
        Node* node = root;
        for(char ch : word){
            cout << "char" << ch << endl;
            if(!node->containsKey(ch)){
                return false;
            }
            node = node->links[ch-'a'];
        }
        return node->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(char ch : prefix){
            if(!node->containsKey(ch)){
                return false;
            }
            node = node->links[ch-'a'];
        }
        return true;
    }
};