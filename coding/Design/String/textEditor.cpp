// https://leetcode.com/problems/design-a-text-editor/description/

// Appraoch 1 : using string functions like insert, erase, substr 


// Time : O(n) : n is the length of the string
// Space : O(n) : n is the length of the string

class TextEditor {
    public:
        string str = "";
        int len = 0;
        int cursorPos = 0;
        TextEditor() {
            
        }
        
        void addText(string text) {
            str.insert(cursorPos, text);
            cursorPos += text.size();
            len = str.size();
        }
        
        int deleteText(int k) {
            if(cursorPos <= k){
                str.erase(0, cursorPos);
                int numOfChar = cursorPos;
                cursorPos = 0;
                len = str.size();
                return numOfChar;
            }else {
                str.erase(cursorPos-k, k);
                cursorPos -= k;
                len = str.size();
                return k;
            }
        }
        
        string cursorLeft(int k) {
            if(cursorPos >= k){
                cursorPos -= k;
            }else{
                cursorPos = 0;
            }
            string s = "";
            if(cursorPos > 10){
                s = str.substr(cursorPos-10, 10);
            }else {
                s = str.substr(0, cursorPos);
            }
            return s;
        }
        
        string cursorRight(int k) {
            if(len - cursorPos >= k){
                cursorPos += k;
            }else{
                cursorPos = len;
            }
            string s = "";
            if(cursorPos - 0 > 10){
                s = str.substr(cursorPos-10, 10);
            }else {
                s = str.substr(0, cursorPos);
            }
            return s;
        }
    };

// Approach 2 : using stack
// left stack and right stack
// left stack will store the char to the left of the cursor
// right stack will store the char to the right of the cursor

// Time : O(k) : n is the length of the string
// Space : O(n) : n is the length of the string

class TextEditor {
    public:
        string str;
        int cursorPos;
    
        TextEditor() {
            str = "";
            cursorPos = 0;
        }
    
        void addText(string text) {
            str.insert(cursorPos, text);  // O(n), but better than rebuilding string
            cursorPos += text.length();
        }
    
        int deleteText(int k) {
            int actualDelete = min(k, cursorPos);
            str.erase(cursorPos - actualDelete, actualDelete);
            cursorPos -= actualDelete;
            return actualDelete;
        }
    
        string cursorLeft(int k) {
            cursorPos = max(0, cursorPos - k);
            int start = max(0, cursorPos - 10);
            return str.substr(start, cursorPos - start);
        }
    
        string cursorRight(int k) {
            cursorPos = min((int)str.length(), cursorPos + k);
            int start = max(0, cursorPos - 10);
            return str.substr(start, cursorPos - start);
        }
    };
    