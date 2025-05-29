// https://leetcode.com/problems/implement-queue-using-stacks/submissions/1611032930/

class MyQueue {
    public:
        stack<int>s1;
        stack<int>s2;
        MyQueue() {
            
        }
        
        void push(int x) {
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
            s1.push(x);
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        int pop() {
            int x = -1;
            if(s1.empty() && s2.empty()){
                return x;
            }else if(!s2.empty()){
                x = s2.top();
                s2.pop();
                return x;
            }
            return -1;
        }
        
        int peek() {
           int x = -1;
            if(s1.empty() && s2.empty()){
                return x;
            }else if(!s2.empty()){
                x = s2.top();
                return x;
            }
            return -1;
        }
        
        bool empty() {
             if(s1.empty() && s2.empty()){
                return true;
            }else {
                return false;
            }
        }
    };